//
// Created by Le Gall on 15/11/2023.
//

#include "manageInts.h"

int lenOfInt(unsigned long long value) {
    int len = 0;
    if (value == 0) {
        return 1;
    }
    while (value >= 1) {
        value = value / 10;
        len++;
    }
    return len;
}

void printGap(unsigned long long value) {
    int lenOfValue = lenOfInt(value);
    for (int i = 0; i < lenOfValue; ++i) {
        printf("-");
    }
    printf("---------");
}

unsigned long long getLongRandomNumber() {
    unsigned long long r = 0;
    for (int i = 0; i < 5; ++i) {
        r = (r << 15) | (rand() & 0x7FFF);
    }
    return r & 0xFFFFFFFFFFFFFFFFULL;
}

unsigned int nbDivideBy2(int value) {
    unsigned int result = 0;
    while (((value % 2) == 0) && (value != 0)) {
        value = value / 2;
        result++;
    }
    return result;
}