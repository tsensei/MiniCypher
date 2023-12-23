#include "../include/caseConversion.h"
#include <string.h>

char *caseConversion(char str[], const char *key)
{
    int len = strlen(str);
    int convertToUpper = strcmp(key, "Uppercase") == 0;

    for (int i = 0; i < len; i++)
    {
        if (convertToUpper)
        {
            // Convert to uppercase if character is lowercase
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] = str[i] - ('a' - 'A');
            }
        }
        else
        {
            // Convert to lowercase if character is uppercase
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] = str[i] + ('a' - 'A');
            }
        }
    }

    return str;
}
