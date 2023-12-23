#include "../include/rot.h"
#include <string.h>
#include <stdlib.h>

char *rot(const char *string, int key) {
    if (string == NULL) {
        return NULL;
    }

    int length = strlen(string);
    char *transformed = malloc(length + 1); // +1 for null terminator

    if (transformed == NULL) {
        return NULL; // Memory allocation failed
    }

    // Ensure the key is within 0-25
    key = key % 26;

    for (int i = 0; string[i] != '\0'; i++) {
        transformed[i] = string[i];

        if (transformed[i] >= 'a' && transformed[i] <= 'z') {
            transformed[i] = ((transformed[i] - 'a' + key) % 26) + 'a';
        } else if (transformed[i] >= 'A' && transformed[i] <= 'Z') {
            transformed[i] = ((transformed[i] - 'A' + key) % 26) + 'A';
        }
    }

    transformed[length] = '\0'; // Null-terminate the string

    return transformed;
}
