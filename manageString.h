//
// Created by hugol on 23/11/2023.
//

#ifndef PROJET_C_L2_3_MANAGESTRING_H
#define PROJET_C_L2_3_MANAGESTRING_H

#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#include <math.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    char **array;
    unsigned int size;
} StringArray;

unsigned int countStringArrayElements(const char *array, const char *delimiter);

StringArray splitStringToArray(const char *stringToSplit, const char *delimiter);

void deleteString(StringArray string);

int isDigit(char *string);

int convertStringToDigit(char *string);

char *scanString(void);

void toLowerCase(char *string);

void printGapChar(char *name);


#endif //PROJET_C_L2_3_MANAGESTRING_H
