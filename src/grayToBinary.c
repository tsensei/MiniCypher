#include "../include/grayToBinary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* grayToBinary(const char* grayCode) {
    if (grayCode == NULL) {
        return NULL;
    }

    int len = strlen(grayCode);
    char* binary = malloc((len + 1) * sizeof(char)); // Allocate memory for the binary string
    if (binary == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    binary[0] = grayCode[0];
    for (int i = 1; i < len; i++) {
        binary[i] = (grayCode[i] == '0' && binary[i - 1] == '0') || (grayCode[i] == '1' && binary[i - 1] == '1') ? '0' : '1';
    }
    binary[len] = '\0'; // Null-terminate the string

    return binary;
}