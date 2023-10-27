//
// Created by Le Gall on 27/10/2023.
//

#include "stringStruct.h"

StringStruct *createStringStruct(char* value){
    StringStruct *newString = (StringStruct*) malloc(sizeof (StringStruct));
    newString->value = (char*) malloc(strlen(value)*sizeof (char));
    strcpy(newString->value, value);
    return newString;
}

void displayStringStruct(StringStruct* stringStruct){
    printf("%s", stringStruct->value);
}

void printGapOfString(StringStruct* stringStruct){
    for (int i = 0; i < strlen(stringStruct->value); ++i) {
        printf("-");
    }
    printf("--------");
}

void deleteStringStruct(StringStruct* stringStruct){
    free(stringStruct->value);
    free(stringStruct);
}
