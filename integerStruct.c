//
// Created by Le Gall on 27/10/2023.
//

#include "integerStruct.h"

IntegerStruct *createIntegerStruct(int value){
    IntegerStruct *newInteger = (IntegerStruct*) malloc(sizeof (IntegerStruct));
    newInteger->value = value;
    return newInteger;
}
void displayIntegerStruct(IntegerStruct* integer){
    printf("%d", integer->value);
}
void deleteIntegerStruct(IntegerStruct* integer){
    free(integer);
}

int lenOfInt(IntegerStruct* integer) {
    int len = 0;
    int value = integer->value;
    if (value == 0) {
        return 1;
    }
    value = abs(value);
    while (value >= 1) {
        value = value / 10;
        len++;
    }
    return len;
}

void printGapOfInt(IntegerStruct* integer) {
    int lenOfValue = lenOfInt(integer);
    for (int i = 0; i < lenOfValue; ++i) {
        printf("-");
    }
    printf("--------");
}
