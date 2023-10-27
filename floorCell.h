//
// Created by Le Gall on 26/10/2023.
//

#ifndef PROJET_C_L2_FLOORCELL_H
#define PROJET_C_L2_FLOORCELL_H
#include "string.h"
#include "integerStruct.h"
#include "charachterStruct.h"
#include "stringStruct.h"

typedef enum{
    integer, character, string
}allTypes;

typedef struct FloorCell{
    void* value;
    allTypes type;
    struct FloorCell** arrayOfNexts;
    int nbFloors;
}FloorCell;

FloorCell *createFloorCellWithInteger(int value, int nbFloors);
FloorCell *createFloorCell(void* value, allTypes type, int nbFloors);
void deleteFloorCell(FloorCell* floorCell);
FloorCell **createArrayOfNexts(int nbFloors);
int isEmptyArrayOfFloorCell(FloorCell** ArrayOfFloorCell, int size);
void displayFloorCell(FloorCell *floorCell);
void displayGap(FloorCell *floorCell);


#endif //PROJET_C_L2_FLOORCELL_H
