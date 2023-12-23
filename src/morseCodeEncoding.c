#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include "../include/morseCodeEncoding.h"

const char *morseEncode(char x)
{
    
    switch (x)
    {
    case 'a':
        return ".-";
    case 'b':
        return "-...";
    case 'c':
        return "-.-.";
    case 'd':
        return "-..";
    case 'e':
        return ".";
    case 'f':
        return "..-.";
    case 'g':
        return "--.";
    case 'h':
        return "....";
    case 'i':
        return "..";
    case 'j':
        return ".---";
    case 'k':
        return "-.-";
    case 'l':
        return ".-..";
    case 'm':
        return "--";
    case 'n':
        return "-.";
    case 'o':
        return "---";
    case 'p':
        return ".--.";
    case 'q':
        return "--.-";
    case 'r':
        return ".-.";
    case 's':
        return "...";
    case 't':
        return "-";
    case 'u':
        return "..-";
    case 'v':
        return "...-";
    case 'w':
        return ".--";
    case 'x':
        return "-..-";
    case 'y':
        return "-.--";
    case 'z':
        return "--..";
    case '1':
        return ".----";
    case '2':
        return "..---";
    case '3':
        return "...--";
    case '4':
        return "....-";
    case '5':
        return ".....";
    case '6':
        return "-....";
    case '7':
        return "--...";
    case '8':
        return "---..";
    case '9':
        return "----.";
    case '0':
        return "-----";
    case '.':
        return ".-.-.-";
    case ',':
        return "--..--";
    case '?':
        return "..--..";
    case '\'':
        return ".----.";
    case '!':
        return "-.-.--";
    case '/':
        return "-..-.";
    case '(':
        return "-.--.";
    case ')':
        return "-.--.-";
    case '&':
        return ".-...";
    case ':':
        return "---...";
    case ';':
        return "-.-.-.";
    case '=':
        return "-...-";
    case '+':
        return ".-.-.";
    case '-':
        return "-....-";
    case '_':
        return "..--.-";
    case '"':
        return ".-..-.";
    case '$':
        return "...-..-";
    case '@':
        return ".--.-.";
    default:
        return "?"; // This will now be used only for truly invalid or unsupported characters
    }
}

char morseDecode(const char *x)
{
    if (strcmp(x, ".-") == 0)
    {
        return 'a';
    }
    else if (strcmp(x, "-...") == 0)
    {
        return 'b';
    }
    else if (strcmp(x, "-.-.") == 0)
    {
        return 'c';
    }
    else if (strcmp(x, "-..") == 0)
    {
        return 'd';
    }
    else if (strcmp(x, ".") == 0)
    {
        return 'e';
    }
    else if (strcmp(x, "..-.") == 0)
    {
        return 'f';
    }
    else if (strcmp(x, "--.") == 0)
    {
        return 'g';
    }
    else if (strcmp(x, "....") == 0)
    {
        return 'h';
    }
    else if (strcmp(x, "..") == 0)
    {
        return 'i';
    }
    else if (strcmp(x, ".---") == 0)
    {
        return 'j';
    }
    else if (strcmp(x, "-.-") == 0)
    {
        return 'k';
    }
    else if (strcmp(x, ".-..") == 0)
    {
        return 'l';
    }
    else if (strcmp(x, "--") == 0)
    {
        return 'm';
    }
    else if (strcmp(x, "-.") == 0)
    {
        return 'n';
    }
    else if (strcmp(x, "---") == 0)
    {
        return 'o';
    }
    else if (strcmp(x, ".--.") == 0)
    {
        return 'p';
    }
    else if (strcmp(x, "--.-") == 0)
    {
        return 'q';
    }
    else if (strcmp(x, ".-.") == 0)
    {
        return 'r';
    }
    else if (strcmp(x, "...") == 0)
    {
        return 's';
    }
    else if (strcmp(x, "-") == 0)
    {
        return 't';
    }
    else if (strcmp(x, "..-") == 0)
    {
        return 'u';
    }
    else if (strcmp(x, "...-") == 0)
    {
        return 'v';
    }
    else if (strcmp(x, ".--") == 0)
    {
        return 'w';
    }
    else if (strcmp(x, "-..-") == 0)
    {
        return 'x';
    }
    else if (strcmp(x, "-.--") == 0)
    {
        return 'y';
    }
    else if (strcmp(x, "--..") == 0)
    {
        return 'z';
    }
    else if (strcmp(x, ".----") == 0)
    {
        return '1';
    }
    else if (strcmp(x, "..---") == 0)
    {
        return '2';
    }
    else if (strcmp(x, "...--") == 0)
    {
        return '3';
    }
    else if (strcmp(x, "....-") == 0)
    {
        return '4';
    }
    else if (strcmp(x, ".....") == 0)
    {
        return '5';
    }
    else if (strcmp(x, "-....") == 0)
    {
        return '6';
    }
    else if (strcmp(x, "--...") == 0)
    {
        return '7';
    }
    else if (strcmp(x, "---..") == 0)
    {
        return '8';
    }
    else if (strcmp(x, "----.") == 0)
    {
        return '9';
    }
    else if (strcmp(x, "-----") == 0)
    {
        return '0';
    }
    else
    {
        return '?';
    }
}



char *asciiToMorse(const char *input) {
    if (input == NULL) {
        fprintf(stderr, "Input string is null\n");
        return NULL;
    }

    int maxMorseLength = strlen(input) * 5; 
    char *morseStr = malloc(maxMorseLength + 1); 
    if (morseStr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    
    morseStr[0] = '\0'; 
    for (int i = 0; input[i] != '\0'; i++) {
        const char *code = morseEncode(tolower(input[i])); 
        strcat(morseStr, code); 
        strcat(morseStr, " "); 
    }

    return morseStr;
}

char *morseToAscii(const char *input) {
    if (input == NULL) {
        fprintf(stderr, "Input string is null\n");
        return NULL;
    }

    int maxAsciiLength = strlen(input) / 5; 
    char *asciiStr = malloc(maxAsciiLength + 1); 
    if (asciiStr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    
    asciiStr[0] = '\0'; 
    char *token = strtok((char *)input, " "); 
    while (token != NULL) {
        char asciiChar = morseDecode(token); 
        if (asciiChar == '?') {
            // Append an error message instead of the invalid character
            strcat(asciiStr, "[error: invalid Morse sequence]");
        } else {
            strncat(asciiStr, &asciiChar, 1);
        }
        token = strtok(NULL, " "); 
    }

    return asciiStr;
}