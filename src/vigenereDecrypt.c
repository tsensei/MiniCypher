#include "../include/vigenereDecrypt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *vigenereDecrypt(const char *text, const char *key) {
    if (text == NULL || key == NULL) {
        return NULL;
    }

    int cipherLen = strlen(text);
    int keyLen = strlen(key);
    char *decrypted = malloc(cipherLen + 1); // +1 for null terminator

    if (!decrypted) {
        return NULL; // Memory allocation failed
    }

    for (int i = 0; i < cipherLen; i++) {
        int ci = text[i] - 'A';
        int ki = key[i % keyLen] - 'A';
        char pi = (ci - ki + 26) % 26 + 'A';
        decrypted[i] = pi;
    }
    decrypted[cipherLen] = '\0';

    return decrypted;
}
