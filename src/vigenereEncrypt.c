#include "../include/vigenereEncrypt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *vigenereEncrypt(const char *plaintext, const char *keyword) {
    if (plaintext == NULL || keyword == NULL) {
        return NULL;
    }

    int plainLen = strlen(plaintext);
    int keyLen = strlen(keyword);
    char *encrypted = malloc(plainLen + 1); // +1 for null terminator

    if (!encrypted) {
        return NULL; // Memory allocation failed
    }

    for (int i = 0; i < plainLen; i++) {
        int pi = plaintext[i] - 'A';
        int ki = keyword[i % keyLen] - 'A';
        char ci = (pi + ki) % 26 + 'A';
        encrypted[i] = ci;
    }
    encrypted[plainLen] = '\0';

    return encrypted;
}
