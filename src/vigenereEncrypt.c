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
    char *encrypted = malloc(plainLen + 1); 

    if (!encrypted) {
        return NULL;
    }

    for (int i = 0; i < plainLen; i++) {
        if (isalpha(plaintext[i]) && isalpha(keyword[i % keyLen])) {
            int pi = isupper(plaintext[i]) ? plaintext[i] - 'A' : plaintext[i] - 'a';
            int ki = toupper(keyword[i % keyLen]) - 'A';
            int ci = (pi + ki) % 26;

            if (isupper(plaintext[i])) {
                encrypted[i] = ci + 'A';
            } else {
                encrypted[i] = ci + 'a';
            }
        } else {
            encrypted[i] = plaintext[i];
        }
    }
    encrypted[plainLen] = '\0';

    return encrypted;
}
