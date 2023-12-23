#include "../include/binaryToGrayCode.h"
#include<stdio.h>
#include<math.h>

unsigned long long int binaryToGrayCode(unsigned long long int binNum){
    
    unsigned long long int gray = 0;

    int a = 0;
    int b = 0;
    int i = 0;

    while (binNum != 0) {
        a = binNum % 10;
        binNum = binNum / 10;
        b = binNum % 10;

        if ((a && !b) || (!a && b)) {
            gray = gray + pow(10, i);
        }

        i++;
    }
    return gray;
}