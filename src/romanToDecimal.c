#include "../include/romanToDecimal.h"
#include<stdio.h>
#include<string.h>

int getDecimal(char ch)
{
    int num = 0;
    switch (ch) {
    case 'I':
        num = 1;
        break;

    case 'V':
        num = 5;
        break;

    case 'X':
        num = 10;
        break;

    case 'L':
        num = 50;
        break;

    case 'C':
        num = 100;
        break;

    case 'D':
        num = 500;
        break;

    case 'M':
        num = 1000;
        break;

    case '\0':
        num = 0;
        break;

    default:
        num = -1;
    }
    return num;
}

long int romanToDecimal(const char* romanNum) {
    if (romanNum == NULL) {
        return -1; // Or handle error as appropriate
    }

    int i = 0;
    long int result = 0;

    while (romanNum[i]) {
        if ((strlen(romanNum) - i) > 2) {
            if (getDecimal(romanNum[i]) < getDecimal(romanNum[i + 2])) {
                // Handle invalid Roman numeral
                return -1; // Or your preferred method of indicating an error
            }
        }

        if (getDecimal(romanNum[i]) >= getDecimal(romanNum[i + 1])) {
            result = result + getDecimal(romanNum[i]);
        }
        else {
            result = result + (getDecimal(romanNum[i + 1]) - getDecimal(romanNum[i]));
            i++;
        }
        i++;
    }
    
    return result;
}