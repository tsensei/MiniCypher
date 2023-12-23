#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct Converter{
    char  *number;
    char *base;
    char* (*toBinary)(struct Converter *converter);
    char* (*toDecimal)(struct Converter *converter);
    char* (*toOctal)(struct Converter *converter);
    char* (*toHexadecimal)(struct Converter *converter);
} Converter;

// Helper function to convert any base to decimal
long toDecimal(char *number, char *base){
    long decimalNumber = 0, baseValue = 0;
    int i = 0;

    if(strcmp(base, "binary") == 0){
        baseValue = 2;
    }else if(strcmp(base, "octal") == 0){
        baseValue = 8; 
    }else if(strcmp(base, "decimal") == 0){
        baseValue = 10;
    }else if(strcmp(base, "hexadecimal") == 0){
        baseValue = 16;
    }

    decimalNumber = strtol(number, NULL, baseValue);
    return decimalNumber;
}

// Helper function to convert decimal to binary
char* decimalToBinary(long decimalNumber) {
    // Assuming a long is not longer than 64 bits
    static char binaryNumber[65];
    int index = 63;

    binaryNumber[64] = '\0';

    while (decimalNumber > 0) {
        binaryNumber[index] = (decimalNumber % 2) + '0';
        decimalNumber /= 2;
        index--;
    }

    return &binaryNumber[index + 1];
}

char *convertToBinary(Converter *converter) {
    long decimalNumber = toDecimal(converter->number, converter->base);
    return decimalToBinary(decimalNumber);
}

char *convertToDecimal(Converter *converter) {
    static char decimalString[20];
    long decimalNumber = toDecimal(converter->number, converter->base);
    sprintf(decimalString, "%ld", decimalNumber);
    return decimalString;
}

char* decimalToOctal(long decimalNumber) {
    static char octalNumber[23]; // Long can be up to 22 octal digits
    int index = 21;

    octalNumber[22] = '\0';

    if (decimalNumber == 0) {
        octalNumber[21] = '0';
        return &octalNumber[21];
    }

    while (decimalNumber > 0) {
        octalNumber[index] = (decimalNumber % 8) + '0';
        decimalNumber /= 8;
        index--;
    }

    return &octalNumber[index + 1];
}

char *convertToOctal(Converter *converter) {
    long decimalNumber = toDecimal(converter->number, converter->base);
    return decimalToOctal(decimalNumber); // Assuming this returns a static string
}

char* decimalToHex(long decimalNumber) {
    static char hexNumber[17];
    char hexDigits[] = "0123456789ABCDEF";
    int index = 15;

    hexNumber[16] = '\0';

    if (decimalNumber == 0) {
        hexNumber[15] = '0';
        return &hexNumber[15];
    }

    while (decimalNumber > 0) {
        hexNumber[index] = hexDigits[decimalNumber % 16];
        decimalNumber /= 16;
        index--;
    }

    return &hexNumber[index + 1];
}

char *convertToHexadecimal(Converter *converter) {
    long decimalNumber = toDecimal(converter->number, converter->base);
    return decimalToHex(decimalNumber); // Assuming this returns a static string
}

void initConverter(Converter *converter, char *number, char *base){
    converter->number = strdup(number);
    converter->base = strdup(base);
    converter->toBinary = convertToBinary;
    converter->toDecimal = convertToDecimal;
    converter->toOctal = convertToOctal;
    converter->toHexadecimal = convertToHexadecimal;
}