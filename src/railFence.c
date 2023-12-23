#include <stdlib.h>
#include <string.h>
#include "../include/railFence.h"

char *railFenceEncrypt(const char *text, int key) {
    if (text == NULL) return NULL; // Check for NULL pointer
    if (key <= 0) return NULL; // Invalid key value

    int textlen = strlen(text);
    char **railmatrix = (char **)malloc(key * sizeof(char *));
    char *result = (char *)malloc(textlen + 1); // +1 for null terminator

    if (!railmatrix || !result) {
        free(railmatrix);
        free(result);
        return NULL; // Memory allocation failed
    }

    for (int i = 0; i < key; i++) {
        railmatrix[i] = (char *)malloc(textlen * sizeof(char));
        if (!railmatrix[i]) { // Memory allocation check for each row
            for (int j = 0; j < i; j++) free(railmatrix[j]);
            free(railmatrix);
            free(result);
            return NULL;
        }
        memset(railmatrix[i], '\n', textlen); // Initialize to '\n'
    }

    int k = -1, row = 0, col = 0, idx = 0;
    for (int j = 0; j < textlen; j++) {
        railmatrix[row][col++] = text[j];
        if (row == 0 || row == key - 1) k = -k;
        row += k;
    }

    for (int i = 0; i < key; i++) {
        for (int j = 0; j < textlen; j++) {
            if (railmatrix[i][j] != '\n') result[idx++] = railmatrix[i][j];
        }
        free(railmatrix[i]); // Freeing each row after use
    }

    free(railmatrix); // Freeing the array of pointers
    result[idx] = '\0'; // Null-terminate the string
    return result;
}

char *railFenceDecrypt(const char *text, int key) {
    if (text == NULL) return NULL; // Check for NULL pointer
    if (key <= 0) return NULL; // Invalid key value

    int textlen = strlen(text);
    char **railmatrix = (char **)malloc(key * sizeof(char *));
    char *result = (char *)malloc(textlen + 1); // +1 for null terminator

    if (!railmatrix || !result) {
        free(railmatrix);
        free(result);
        return NULL; // Memory allocation failed
    }

    for (int i = 0; i < key; i++) {
        railmatrix[i] = (char *)malloc(textlen * sizeof(char));
        if (!railmatrix[i]) { // Memory allocation check for each row
            for (int j = 0; j < i; j++) free(railmatrix[j]);
            free(railmatrix);
            free(result);
            return NULL;
        }
        memset(railmatrix[i], '\n', textlen); // Initialize to '\n'
    }

    int k = -1, row = 0, col = 0, index = 0, idx = 0;
    for (int i = 0; i < textlen; i++) {
        railmatrix[row][col++] = '*';
        if (row == 0 || row == key - 1) k = -k;
        row += k;
    }

    for (int i = 0; i < key; i++) {
        for (int j = 0; j < textlen; j++) {
            if (railmatrix[i][j] == '*') railmatrix[i][j] = text[index++];
        }
    }

    col = row = 0; k = -1;
    for (int i = 0; i < textlen; ++i) {
        result[idx++] = railmatrix[row][col++];
        if (row == 0 || row == key - 1) k = -k;
        row += k;
    }

    for (int i = 0; i < key; i++) free(railmatrix[i]); // Freeing each row
    free(railmatrix); // Freeing the array of pointers

    result[idx] = '\0'; // Null-terminate the string
    return result;
}