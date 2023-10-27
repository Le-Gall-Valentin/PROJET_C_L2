//
// Created by Le Gall on 26/10/2023.
//

#include "floorCell.h"

FloorCell *createFloorCell(void* value, allTypes type, int nbFloors){
    FloorCell *newFloorCell = (FloorCell*) malloc(sizeof (FloorCell));
    newFloorCell->type = type;
    newFloorCell->value = value;
    newFloorCell->nbFloors = nbFloors;
    newFloorCell->arrayOfNexts = createArrayOfNexts(nbFloors);
    return newFloorCell;
}

FloorCell **createArrayOfNexts(int nbFloors){
    FloorCell **ArrayOfNext = (FloorCell**) malloc( nbFloors * sizeof (FloorCell*));
    for(int i=0; i<nbFloors;i++){
        ArrayOfNext[i] = NULL;
    }
    return ArrayOfNext;
}

int isEmptyArrayOfFloorCell(FloorCell** ArrayOfFloorCell, int size){
    for(int i=0 ; i<size; i++){
        if(ArrayOfFloorCell[i] != NULL){
            return 0;
        }
    }
    return 1;
}

void deleteFloorCell(FloorCell* floorCell){
    free(floorCell->arrayOfNexts);
    free(floorCell);
}

void displayFloorCell(FloorCell *floorCell){
    switch (floorCell->type) {
        case integer:
            printf("[");
            displayIntegerStruct((IntegerStruct*)floorCell->value);
            printf("|@ ]");
            break;
        case character:
            printf("[");
            displayCharacterStruct((CharacterStruct *)floorCell->value);
            printf("|@ ]");
            break;
        case string:
            printf("[");
            displayStringStruct((StringStruct *)floorCell->value);
            printf("|@ ]");
            break;
    }
}

void displayGap(FloorCell *floorCell){
    switch (floorCell->type) {
        case integer:
            printGapOfInt((IntegerStruct*)floorCell->value);
            break;
        case character:
            printGapOfChar((CharacterStruct*)floorCell->value);
            break;
        case string:
            printGapOfString((StringStruct*)floorCell->value);
            break;
    }
}
