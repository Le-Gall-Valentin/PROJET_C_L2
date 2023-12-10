//
// Created by Le Gall on 26/10/2023.
//


#include "floorCell.h"


FloorCell *createFloorCell(unsigned long long value, int nbFloors) {
    // Initialise une new cell avec les valeurs données en paramètre
    FloorCell *newFloorCell = (FloorCell *) malloc(sizeof(FloorCell));
    newFloorCell->value = value;
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
    // Test toutes les cases du tableau vérifiant si elles sont nulles
    for (int i = 0; i < size; i++) {
        if (ArrayOfFloorCell[i] != NULL) {
            return 0;
        }
    }
    return 1;
}

void deleteFloorCell(FloorCell *floorCell) {
    //Supprime une Cell
    free(floorCell->arrayOfNexts);
    free(floorCell);
}

void displayFloorCell(FloorCell *floorCell) {
    // Affiche la valeur de la Cell
    printf("[ %lld|@ ]", floorCell->value);
}
