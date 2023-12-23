#include "../include/runLengthEncoding.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *runLengthEncoding(const char *input) {
    if (input == NULL) {
        return NULL;
    }

    int length = strlen(input);
    // Allocate enough memory (worst case: 2 characters for each input character)
    char *encoded = malloc(2 * length + 1);
    if (!encoded) {
        return NULL; // Memory allocation failed
    }

    int count, idx = 0;
    for (int i = 0; i < length; i++) {
        count = 1;
        while (i < length - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }

        // Write count and character to the encoded string
        int numChars = sprintf(encoded + idx, "%d%c", count, input[i]);
        idx += numChars;
    }
    encoded[idx] = '\0'; // Null-terminate the string

    return encoded;
}
