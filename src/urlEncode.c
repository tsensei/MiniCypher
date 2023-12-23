#include "../include/urlEncode.h"
#include <string.h>
#include <stdlib.h>

char *urlEncode(const char *string) {
    if (string == NULL) {
        return NULL;
    }

    const char hex[] = "0123456789ABCDEF";
    size_t len = strlen(string);
    // Allocate enough memory (worst case: each char becomes '%XX')
    char *encoded = malloc(3 * len + 1); // 3 times the length for '%XX' + 1 for null terminator

    if (!encoded) {
        return NULL; // Memory allocation failed
    }

    size_t j = 0;
    for (size_t i = 0; i < len; ++i) {
        if ((string[i] >= 'A' && string[i] <= 'Z') ||
            (string[i] >= 'a' && string[i] <= 'z') ||
            (string[i] >= '0' && string[i] <= '9') ||
            string[i] == '-' || string[i] == '_' || string[i] == '.' || string[i] == '~') {
            encoded[j++] = string[i];
        } else if (string[i] == ' ') {
            encoded[j++] = '+';
        } else {
            encoded[j++] = '%';
            encoded[j++] = hex[(string[i] >> 4) & 0xF];
            encoded[j++] = hex[string[i] & 0xF];
        }
    }
    encoded[j] = '\0';

    return encoded;
}
