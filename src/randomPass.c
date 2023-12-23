#include "../include/randomPass.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char *randomPass(int length) {
    if (length <= 0) {
        fprintf(stderr, "Invalid length\n");
        return NULL;
    }

    char lower[] = "abcdefghijklmnopqrstuvwxyz";
    char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char digit[] = "0123456789";
    char special[] = "!@#$%^&*()_+-=]};:,.<>?";

    // seeding the rand() with current time
    srand((unsigned)time(NULL));

    // Allocate memory for the password
    char *password = malloc(length + 1); // +1 for null terminator
    if (!password) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    // Character set that combines all types
    char allChars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=]};:,.<>?";

    for (int i = 0; i < length; i++) {
        int index = rand() % strlen(allChars); // random index
        password[i] = allChars[index];
    }
    password[length] = '\0'; // Null-terminate the password

    return password;
}
