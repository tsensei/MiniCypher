#include "../include/XORcipher.h"
#include <string.h>
#include <stdlib.h>

char *xorcipher(const char *str, char key) {
    if (str == NULL) {
        return NULL;
    }

    int len = strlen(str);
    char *ciphered = malloc(len + 1); // +1 for null terminator

    if (!ciphered) {
        return NULL; // Memory allocation failed
    }

    for (int i = 0; i < len; i++) {
        ciphered[i] = str[i] ^ key;
    }
    ciphered[len] = '\0';

    return ciphered;
}
