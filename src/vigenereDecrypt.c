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
    char *decrypted = malloc(cipherLen + 1); 

    if (!decrypted) {
        return NULL; 
    }

    for (int i = 0; i < cipherLen; i++) {
        if (isalpha(text[i]) && isalpha(key[i % keyLen])) {
            int ci = isupper(text[i]) ? text[i] - 'A' : text[i] - 'a';
            int ki = toupper(key[i % keyLen]) - 'A';
            int pi = (ci - ki + 26) % 26;

            if (isupper(text[i])) {
                decrypted[i] = pi + 'A';
            } else {
                decrypted[i] = pi + 'a';
            }
        } else {
            decrypted[i] = text[i];
        }
    }
    decrypted[cipherLen] = '\0';

    return decrypted;
}
