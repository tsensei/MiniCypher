#include "../include/vigenereEncrypt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *vigenereEncrypt(const char *plaintext, const char *keyword) {
    if (plaintext == NULL || keyword == NULL || keyword[0] == '\0') {
        return NULL;
    }

    int plainLen = strlen(plaintext);
    int keyLen = strlen(keyword);
    char *encrypted = malloc(plainLen + 1); // +1 for null terminator

    if (!encrypted) {
        return NULL; // Memory allocation failed
    }

    for (int i = 0; i < plainLen; i++) {
        if (isalpha(plaintext[i]) && isalpha(keyword[i % keyLen])) {
            int pi = toupper(plaintext[i]) - 'A';
            int ki = toupper(keyword[i % keyLen]) - 'A';
            char ci = (pi + ki) % 26 + 'A';
            encrypted[i] = ci;
        } else {
            encrypted[i] = plaintext[i];
        }
    }
    encrypted[plainLen] = '\0';

    return encrypted;
}