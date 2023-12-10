//
// Created by Le Gall on 26/10/2023.
//


#include "floorCell.h"


FloorCell *createFloorCell(Contact *contact, int nbFloors) {
    // Alloue de la mémoire pour la nouvelle structure FloorCell
    FloorCell *newFloorCell = (FloorCell *) malloc(sizeof(FloorCell));

    // Initialise le champ value avec le contact fourni
    newFloorCell->value = contact;

    // Initialise le nombre d'étages de la cellule
    newFloorCell->nbFloors = nbFloors;

    // Initialise le tableau de pointeurs vers les cellules suivantes
    newFloorCell->arrayOfNexts = createArrayOfNexts(nbFloors);

    // Retourne la nouvelle cellule créée
    return newFloorCell;
}

FloorCell **createArrayOfNexts(int nbFloors) {
    // Alloue de la mémoire pour le tableau de pointeurs vers les cellules suivantes
    FloorCell **ArrayOfNext = (FloorCell **) malloc(nbFloors * sizeof(FloorCell *));

    // Initialise chaque élément du tableau à NULL
    for (int i = 0; i < nbFloors; i++) {
        ArrayOfNext[i] = NULL;
    }

    // Retourne le tableau de pointeurs initialisé
    return ArrayOfNext;
}

void deleteFloorCell(FloorCell *floorCell) {
    //Supprime une FloorCell
    free(floorCell->arrayOfNexts);
    free(floorCell);
}

void displayFloorCellName(FloorCell *floorCell) {
    // Affiche le nom et prénom du contact associé à la cellule
    printf("[ %s|@ ]", floorCell->value->lastnameFirstname);
}
