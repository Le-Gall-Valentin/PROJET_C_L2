//
// Created by Le Gall on 26/10/2023.
//


#include "floorCell.h"


FloorCell *createFloorCell(Contact *contact, int nbFloors) {
    FloorCell *newFloorCell = (FloorCell *) malloc(sizeof(FloorCell));
    newFloorCell->value = contact;
    newFloorCell->nbFloors = nbFloors;
    newFloorCell->arrayOfNexts = createArrayOfNexts(nbFloors);
    return newFloorCell;
}

FloorCell **createArrayOfNexts(int nbFloors) {
    FloorCell **ArrayOfNext = (FloorCell **) malloc(nbFloors * sizeof(FloorCell *));
    for (int i = 0; i < nbFloors; i++) {
        ArrayOfNext[i] = NULL;
    }
    return ArrayOfNext;
}

int isEmptyArrayOfFloorCell(FloorCell **ArrayOfFloorCell, int size) {
    for (int i = 0; i < size; i++) {
        if (ArrayOfFloorCell[i] != NULL) {
            return 0;
        }
    }
    return 1;
}

void deleteFloorCell(FloorCell *floorCell) {
    free(floorCell->arrayOfNexts);
    free(floorCell);
}

void displayFloorCellName(FloorCell *floorCell) {
    printf("[ %s|@ ]", floorCell->value->lastnameFirstname);
}

void displayFloorCellAllInformations(FloorCell *floorCell) {
    if (floorCell != NULL) {
        displayContact(floorCell->value);
    }
}
