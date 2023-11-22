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

void addHeadFloorList(ListOfFloorCells *list, unsigned long long value, int nbFloors);

void addSortedCellInFloorList(ListOfFloorCells *list, unsigned long long value, int nbFloors);

void displayFloorList(ListOfFloorCells *list);

void displayOneFloorOfFloorList(ListOfFloorCells *list, int floor);

ListOfFloorCells *createSortedListWithNValues(int n);

int classicSearchValueInFloorList(ListOfFloorCells *list, unsigned long long value);

int levelSearchValueInFloorList(ListOfFloorCells *list, unsigned long long value);

void deleteFloorList(ListOfFloorCells *list);

#endif //PROJET_C_L2_LISTOFFLOORCELLS_H
