#include "../include/reverseString.h"
#include <string.h>
#include <stdlib.h>

char *reverse(const char *string) {
    if (string == NULL) {
        return NULL;
    }

    int length = strlen(string);
    char *reversed = malloc(length + 1); // +1 for null terminator

    if (reversed == NULL) {
        return NULL; // Memory allocation failed
    }

    for (int i = 0; i < length; i++) {
        reversed[i] = string[length - 1 - i];
    }
    reversed[length] = '\0'; // Null-terminate the string

    return reversed;
}
