//
// Created by Le Gall on 27/10/2023.
//

#ifndef PROJET_C_L2_CHARACHTERSTRUCT_H
#define PROJET_C_L2_CHARACHTERSTRUCT_H
#include "stdlib.h"
#include "stdio.h"

typedef struct CharacterStruct{
    char value;
}CharacterStruct;

CharacterStruct *createCharStruct(char value);
void displayCharacterStruct(CharacterStruct* characterStruct);
void printGapOfChar(CharacterStruct* characterStruct);
void deleteCharacterStruct(CharacterStruct* characterStruct);

#endif //PROJET_C_L2_CHARACHTERSTRUCT_H
