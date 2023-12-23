#include "../include/bitwiseAND_OR_NOT.h"
#include <stdio.h>

int bitwiseAND(int input1, int input2) {
    int result;
    
    result = input1 & input2;

    return result;
}

int bitwiseOR(int input1, int input2) {
    int result;

    result = input1 | input2;
    
    return result;
}

int bitwiseNOT(int input) {
    int result;

    result = ~input;

    return result;
}
