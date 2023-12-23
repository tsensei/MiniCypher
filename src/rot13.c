#include "../include/rot13.h"
#include <string.h>
#include <stdlib.h>

char *rot(const char *string) {
    if (string == NULL) {
        return NULL;
    }

    int length = strlen(string);
    char *transformed = malloc(length + 1); // +1 for null terminator

    if (transformed == NULL) {
        return NULL; // Memory allocation failed
    }

    for (int i = 0; string[i] != '\0'; i++) {
        transformed[i] = string[i];
        if ((transformed[i] >= 'a' && transformed[i] <= 'z') || (transformed[i] >= 'A' && transformed[i] <= 'Z')) {
            if ((transformed[i] >= 'a' && transformed[i] <= 'm') || (transformed[i] >= 'A' && transformed[i] <= 'M')) {
                transformed[i] += 13;
            } else {
                transformed[i] -= 13;
            }
        }
    }
    transformed[length] = '\0'; // Null-terminate the string

    return transformed;
}
