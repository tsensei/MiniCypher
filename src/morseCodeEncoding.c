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
    default:
        fprintf(stderr, "Found invalid character: %c\n", x);
        exit(1);
    }
}


char *morseCodeEncoding(char *input) {
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