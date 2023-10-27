//
// Created by Le Gall on 27/10/2023.
//

#ifndef PROJET_C_L2_INTEGERSTRUCT_H
#define PROJET_C_L2_INTEGERSTRUCT_H
#include "stdlib.h"
#include "stdio.h"

typedef struct IntegerStruct{
    int value;
}IntegerStruct;

IntegerStruct *createIntegerStruct(int value);
void displayIntegerStruct(IntegerStruct* integer);
int lenOfInt(IntegerStruct* integer);
void printGapOfInt(IntegerStruct* integer);
void deleteIntegerStruct(IntegerStruct* integer);

#endif //PROJET_C_L2_INTEGERSTRUCT_H
