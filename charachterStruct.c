//
// Created by Le Gall on 27/10/2023.
//

#include "charachterStruct.h"

CharacterStruct *createCharStruct(char value){
    CharacterStruct *newCharacter = (CharacterStruct*) malloc(sizeof (CharacterStruct));
    newCharacter->value = value;
    return newCharacter;
}
void displayCharacterStruct(CharacterStruct* characterStruct){
    printf("%c", characterStruct->value);
}
void deleteCharacterStruct(CharacterStruct* characterStruct){
    free(characterStruct);
}

void printGapOfChar(CharacterStruct* characterStruct){
    printf("---------");
}

