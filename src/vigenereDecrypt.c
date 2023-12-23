#include "../include/vigenereDecrypt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *vigenereDecrypt(const char *text, const char *key) {
    if (text == NULL || key == NULL || key[0] == '\0') {
        return NULL;
    }

    int cipherLen = strlen(text);
    int keyLen = strlen(key);
    char *decrypted = malloc(cipherLen + 1); // +1 for null terminator

    if (!decrypted) {
        return NULL; // Memory allocation failed
    }

    for (int i = 0; i < cipherLen; i++) {
        if (isalpha(text[i]) && isalpha(key[i % keyLen])) {
            int ci = toupper(text[i]) - 'A';
            int ki = toupper(key[i % keyLen]) - 'A';
            char pi = (ci - ki + 26) % 26 + 'A';
            decrypted[i] = pi;
        } else {
            decrypted[i] = text[i];
        }
    }
    decrypted[cipherLen] = '\0';

    return decrypted;
}