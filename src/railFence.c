#include <stdlib.h>
#include <string.h>
#include "../include/railFence.h"

char *railFenceEncrypt(const char *text, int key) {
    int textlen = strlen(text);
    char railmatrix[key][textlen];
    char *result = malloc(textlen + 1); // +1 for null terminator
    int i, j, k = -1, row = 0, col = 0, idx = 0;

    if (!result) return NULL; // Check for memory allocation failure

    for (i = 0; i < key; i++)
        for (j = 0; j < textlen; j++)
            railmatrix[i][j] = '\n';

    for (j = 0; j < textlen; j++) {
        railmatrix[row][col++] = text[j];
        if (row == 0 || row == key - 1) k = k * (-1);
        row += k;
    }

    for (i = 0; i < key; ++i)
        for (j = 0; j < textlen; ++j)
            if (railmatrix[i][j] != '\n')
                result[idx++] = railmatrix[i][j];

    result[idx] = '\0'; // Null-terminate the string
    return result;
}


char *railFenceDecrypt(const char *text, int key) {
    int textlen = strlen(text);
    char railmatrix[key][textlen];
    char *result = malloc(textlen + 1); // +1 for null terminator
    int i, j, k = -1, row = 0, col = 0, index = 0, idx = 0;

    if (!result) return NULL; // Check for memory allocation failure

    for (i = 0; i < key; i++)
        for (j = 0; j < textlen; j++)
            railmatrix[i][j] = '\n';

    for (i = 0; i < textlen; i++) {
        railmatrix[row][col++] = '*';
        if (row == 0 || row == key - 1) k *= (-1);
        row += k;
    }

    for (i = 0; i < key; i++)
        for (j = 0; j < textlen; j++)
            if (railmatrix[i][j] == '*')
                railmatrix[i][j] = text[index++];

    col = row = 0; k = -1;
    for (i = 0; i < textlen; ++i) {
        result[idx++] = railmatrix[row][col++];
        if (row == 0 || row == key - 1) k = k * (-1);
        row += k;
    }

    result[idx] = '\0'; // Null-terminate the string
    return result;
}
