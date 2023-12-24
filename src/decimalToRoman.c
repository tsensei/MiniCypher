#include "../include/decimalToRoman.h"
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

char* decimalToRoman(int num){
    char* RomanNum = malloc(256 * sizeof(char));
    int i = 0;

    if (RomanNum == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    while (num != 0) {
        if (num >= 1000) {
            for (int k = 0; k < num / 1000; k++, i++) {
                RomanNum[i] = 'M';
            }
            num = num - (num / 1000) * 1000;
        }
        else if (num >= 500) {
            if (num < (500 + 4 * 100)) {
                for (int k = 0; k < num / 500; k++, i++) {
                    RomanNum[i] = 'D';
                }
                num = num - (num / 500) * 500;
            }
            else {
                RomanNum[i] = 'C';
                i = i + 1;
                RomanNum[i] = 'M';
                i = i + 1;
                num = num - (1000 - 100);
            }
        }
        else if (num >= 100) {
            if (num < (100 + 3 * 100)) {
                for (int k = 0; k < num / 100; k++, i++) {
                    RomanNum[i] = 'C';
                }
                num = num - (num / 100) * 100;
            }
            else {
                RomanNum[i] = 'L';
                i = i + 1;
                RomanNum[i] = 'D';
                i = i + 1;
                num = num - (500 - 100);
            }
        }
        else if (num >= 50) {
            if (num < (50 + 4 * 10)) {
                for (int k = 0; k < num / 50; k++, i++) {
                    RomanNum[i] = 'L';
                }
                num = num - (num / 50) * 50;
            }
            else {
                RomanNum[i] = 'X';
                i = i + 1;
                RomanNum[i] = 'C';
                i = i + 1;
                num = num - (100 - 10);
            }
        }
        else if (num >= 10) {
            if (num < (10 + 3 * 10)) {
                for (int k = 0; k < num / 10; k++, i++) {
                    RomanNum[i] = 'X';
                }
                num = num - (num / 10) * 10;
            }
            else {
                RomanNum[i] = 'X';
                i = i + 1;
                RomanNum[i] = 'L';
                i = i + 1;
                num = num - (50 - 10);
            }
        }
        else if (num >= 5) {
            if (num < (5 + 4 * 1)) {
                for (int k = 0; k < num / 5; k++, i++) {
                    RomanNum[i] = 'V';
                }
                num = num - (num / 5) * 5;
            }
            else {
                RomanNum[i] = 'I';
                i = i + 1;
                RomanNum[i] = 'X';
                i = i + 1;
                num = num - (10 - 1);
            }
        }
        else if (num >= 1) {
            if (num < 4) {
                for (int k = 0; k < num / 1; k++, i++) {
                    RomanNum[i] = 'I';
                }
                num = num - (num / 1) * 1;
            }
            else {
                RomanNum[i] = 'I';
                i = i + 1;
                RomanNum[i] = 'V';
                i = i + 1;
                num = num - (5 - 1);
            }
        }
    }

    RomanNum[i] = '\0';  
    return RomanNum;
}