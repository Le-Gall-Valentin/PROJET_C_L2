//
// Created by Le Gall on 26/10/2023.
//


#include "floorCell.h"


FloorCell *createFloorCell(Contact *contact, int nbFloors) {
    // Initialise une new cell avec les valeurs données en parramètre
    FloorCell *newFloorCell = (FloorCell *) malloc(sizeof(FloorCell));
    newFloorCell->value = contact;
    newFloorCell->nbFloors = nbFloors;
    newFloorCell->arrayOfNexts = createArrayOfNexts(nbFloors);
    return newFloorCell;
}

FloorCell **createArrayOfNexts(int nbFloors) {
    // initialise le tableau de next à NULL d'une taille nbFloor
    FloorCell **ArrayOfNext = (FloorCell **) malloc(nbFloors * sizeof(FloorCell *));
    for (int i = 0; i < nbFloors; i++) {
        ArrayOfNext[i] = NULL;
    }
    return ArrayOfNext;
}

int isEmptyArrayOfFloorCell(FloorCell **ArrayOfFloorCell, int size) {
    // Test toutes les cases dutableau vérifiant si elles sont nulles
    for (int i = 0; i < size; i++) {
        if (ArrayOfFloorCell[i] != NULL) {
            return 0;
        }
    }
    return 1;
}

void deleteFloorCell(FloorCell *floorCell) {
    //Supprime une FloorCell
    free(floorCell->arrayOfNexts);
    free(floorCell);
}

void displayFloorCellName(FloorCell *floorCell) {
    // Affiche le nom d'une FloorCell
    printf("[ %s|@ ]", floorCell->value->lastnameFirstname);
}

void displayFloorCellAllInformations(FloorCell *floorCell) {
    // Affiche toutes les infos d'un contact
    if (floorCell != NULL) {
        displayContact(floorCell->value);
    }
}
