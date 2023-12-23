#include "../include/urlDecode.h"
#include <string.h>
#include<stdlib.h>

int hextodec(char ch)
{
    if (ch >= '0' && ch <= '9')
    {
        return ch - '0';
    }
    else if (ch >= 'a' && ch <= 'z')
    {
        return ch - 'a' + 10;
    }
    else if (ch >= 'A' && ch <= 'Z')
    {
        return ch - 'A' + 10;
    }
    return 0; // invalid
}

char *urlDecode(const char *str) {
    if (str == NULL) {
        return NULL;
    }

    size_t len = strlen(str);
    char *decoded = malloc(len + 1); // +1 for null terminator

    if (!decoded) {
        return NULL; // Memory allocation failed
    }

    size_t j = 0;
    for (size_t i = 0; i < len && j < len; ++i) {
        if (str[i] == '+') {
            decoded[j++] = ' ';
        } else if (str[i] == '%' && i + 2 < len) {
            decoded[j++] = (char)((hextodec(str[i + 1]) << 4) + hextodec(str[i + 2]));
            i += 2;
        } else {
            decoded[j++] = str[i];
        }
    }
    decoded[j] = '\0';

    return decoded;
}