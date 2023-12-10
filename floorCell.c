//
// Created by Le Gall on 26/10/2023.
//


#include "floorCell.h"


FloorCell *createFloorCell(unsigned long long value, int nbFloors) {
    // Alloue dynamiquement de la mémoire pour une nouvelle instance de FloorCell
    FloorCell *newFloorCell = (FloorCell *) malloc(sizeof(FloorCell));

    // Initialise la valeur et le nombre d'étages
    newFloorCell->value = value;
    newFloorCell->nbFloors = nbFloors;

    // Initialise arrayOfNexts en appelant la fonction createArrayOfNexts
    newFloorCell->arrayOfNexts = createArrayOfNexts(nbFloors);

    // Retourne la nouvelle instance de FloorCell
    return newFloorCell;
}

FloorCell **createArrayOfNexts(int nbFloors) {
    // initialise le tableau de next à NULL d'une taille nbFloor
    FloorCell **ArrayOfNext = (FloorCell **) malloc(nbFloors * sizeof(FloorCell *));

    // Initialise chaque élément du tableau à NULL
    for (int i = 0; i < nbFloors; i++) {
        ArrayOfNext[i] = NULL;
    }

    // Retourne le tableau nouvellement créé
    return ArrayOfNext;
}

void deleteFloorCell(FloorCell *floorCell) {
    // Supprime une Cell

    // Libère la mémoire allouée dynamiquement pour arrayOfNexts
    free(floorCell->arrayOfNexts);

    // Libère la mémoire allouée dynamiquement pour la structure FloorCell elle-même
    free(floorCell);
}

void displayFloorCell(FloorCell *floorCell) {
    // Affiche la valeur de la Cell
    printf("[ %lld|@ ]", floorCell->value);
}
