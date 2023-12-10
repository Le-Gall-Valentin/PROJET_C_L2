//
// Created by Le Gall on 26/10/2023.
//

#ifndef PROJET_C_L2_FLOORCELL_H
#define PROJET_C_L2_FLOORCELL_H

#include <stdlib.h>
#include <stdio.h>

typedef struct FloorCell {
    unsigned long long value;     // Valeur associée à la cellule
    struct FloorCell **arrayOfNexts;  // Tableau de pointeurs vers les cellules suivants
    int nbFloors;                 // Nombre d'étages
} FloorCell;

FloorCell *createFloorCell(unsigned long long value, int nbFloors);

void deleteFloorCell(FloorCell *floorCell);

FloorCell **createArrayOfNexts(int nbFloors);

void displayFloorCell(FloorCell *floorCell);


#endif //PROJET_C_L2_FLOORCELL_H
