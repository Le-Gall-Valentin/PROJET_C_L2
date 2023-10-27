//
// Created by Le Gall on 27/10/2023.
//

#ifndef PROJET_C_L2_STRINGSTRUCT_H
#define PROJET_C_L2_STRINGSTRUCT_H
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef struct StringStruct{
    char* value;
}StringStruct;

StringStruct *createStringStruct(char* value);
void displayStringStruct(StringStruct* stringStruct);
void printGapOfString(StringStruct* stringStruct);
void deleteStringStruct(StringStruct* stringStruct);

#endif //PROJET_C_L2_STRINGSTRUCT_H
