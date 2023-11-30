//
// Created by Le Gall on 26/10/2023.
//

#ifndef PROJET_C_L2_LISTOFFLOORCELLS_H
#define PROJET_C_L2_LISTOFFLOORCELLS_H

#include "floorCell.h"
#include "math.h"
#include "manageInts.h"

typedef struct ListOfFloorCells {
    FloorCell **ArrayOfCell;
    int nbFloors;
} ListOfFloorCells;

ListOfFloorCells *createEmptyFloorList(int nbFloors);

void addHeadFloorList(ListOfFloorCells *list, Contact *contact, int nbFloors);

void addSortedCellInFloorList(ListOfFloorCells *list, Contact *contact);

void displayFloorList(ListOfFloorCells *list);

ListOfFloorCells *createSortedListWithNValues(int n);

FloorCell *classicSearchValueInFloorList(ListOfFloorCells *list, char *name);

FloorCell *levelSearchValueInFloorList(ListOfFloorCells *list, char *name);

void deleteFloorList(ListOfFloorCells *list);

void displayAllValues(ListOfFloorCells *list);

#endif //PROJET_C_L2_LISTOFFLOORCELLS_H
