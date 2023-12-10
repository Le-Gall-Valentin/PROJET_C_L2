//
// Created by Le Gall on 26/10/2023.
//

#ifndef PROJET_C_L2_FLOORCELL_H
#define PROJET_C_L2_FLOORCELL_H

#include <stdlib.h>
#include <stdio.h>
#include "Contact.h"

typedef struct FloorCell {
    Contact *value;               // Référence vers le contact associé à la cellule
    struct FloorCell **arrayOfNexts;  // Tableau de pointeurs vers les cellules suivantes
    int nbFloors;                 // Nombre d'étages de la cellule
} FloorCell;

FloorCell *createFloorCell(Contact *value, int nbFloors);

void deleteFloorCell(FloorCell *floorCell);

FloorCell **createArrayOfNexts(int nbFloors);

void displayFloorCellName(FloorCell *floorCell);


#endif //PROJET_C_L2_FLOORCELL_H
