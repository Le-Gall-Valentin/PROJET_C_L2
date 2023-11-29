//
// Created by Le Gall on 26/10/2023.
//

#ifndef PROJET_C_L2_FLOORCELL_H
#define PROJET_C_L2_FLOORCELL_H
#include <stdlib.h>
#include <stdio.h>
#include "Contact.h"

typedef struct FloorCell {
    Contact *value;
    struct FloorCell **arrayOfNexts;
    int nbFloors;
}FloorCell;

FloorCell *createFloorCell(Contact *value, int nbFloors);

void deleteFloorCell(FloorCell *floorCell);

FloorCell **createArrayOfNexts(int nbFloors);
int isEmptyArrayOfFloorCell(FloorCell** ArrayOfFloorCell, int size);
void displayFloorCell(FloorCell *floorCell);


#endif //PROJET_C_L2_FLOORCELL_H
