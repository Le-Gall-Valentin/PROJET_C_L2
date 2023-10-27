//
// Created by Le Gall on 26/10/2023.
//

#ifndef PROJET_C_L2_LISTOFFLOORCELLS_H
#define PROJET_C_L2_LISTOFFLOORCELLS_H
#include "floorCell.h"

typedef struct ListOfFloorCells{
    FloorCell **ArrayOfCell;
    int nbFloors;
}ListOfFloorCells;

ListOfFloorCells *createEmptyFloorList(int nbFloors);
void addHeadFloorList(ListOfFloorCells* list, void* value, allTypes type, int nbFloors);
void displayFloorList(ListOfFloorCells* list);
void addHeadIntFloorList(ListOfFloorCells *list, int value, int nbFloors);
void addHeadCharFloorList(ListOfFloorCells *list, char value, int nbFloors);
void addHeadStringFloorList(ListOfFloorCells *list, char* value, int nbFloors);
void displayOneFloorOfFloorList(ListOfFloorCells *list, int floor);

#endif //PROJET_C_L2_LISTOFFLOORCELLS_H
