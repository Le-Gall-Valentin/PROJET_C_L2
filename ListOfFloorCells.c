//
// Created by Le Gall on 26/10/2023.
//

#include "ListOfFloorCells.h"


void printGap(int value);
int lenOfInt(int value);

ListOfFloorCells *createEmptyFloorList(int nbFloors) {
    ListOfFloorCells *newFloorList = (ListOfFloorCells *) malloc(sizeof(ListOfFloorCells));
    newFloorList->ArrayOfCell = createArrayOfNexts(nbFloors);
    newFloorList->nbFloors = nbFloors;
    return newFloorList;
}

void addHeadFloorList(ListOfFloorCells *list, int value, int nbFloors) {
    FloorCell *newCell = createFloorCell(value, nbFloors);
    for (int i = 0; i < nbFloors; ++i) {
        newCell->arrayOfNexts[i] = list->ArrayOfCell[i];
    }
    for (int i = 0; i < nbFloors; i++) {
        list->ArrayOfCell[i] = newCell;
    }
}

void displayOneFloorOfFloorList(ListOfFloorCells *list, int floor){
    if(floor <= list->nbFloors-1){
        printf("@ -> ");
        FloorCell *temporaryCell = list->ArrayOfCell[floor];
        while (temporaryCell != NULL){
            displayFloorCell(temporaryCell);
            temporaryCell = temporaryCell->arrayOfNexts[floor];
        }printf("\n");
    }
}

void displayFloorList(ListOfFloorCells *list) {
    for (int i = 0; i < list->nbFloors; ++i) {
        printf("[list head_%d @-]", i);
        FloorCell *temporaryCellFloorI = list->ArrayOfCell[i];
        FloorCell *temporaryCellFloor0 = list->ArrayOfCell[0];
        while (temporaryCellFloor0 != NULL) {
            if(temporaryCellFloor0 == temporaryCellFloorI){
                printf("-->");
                displayFloorCell(temporaryCellFloorI);
                temporaryCellFloorI = temporaryCellFloorI->arrayOfNexts[i];
            }else{
                printGap(temporaryCellFloor0->value);
            }
            temporaryCellFloor0 = temporaryCellFloor0->arrayOfNexts[0];
        }
        printf("-> NULL\n");
    }
}

int lenOfInt(int value) {
    int len = 0;
    if (value == 0) {
        return 1;
    }
    value = abs(value);
    while (value >= 1) {
        value = value / 10;
        len++;
    }
    return len;
}

void printGap(int value) {
    int lenOfValue = lenOfInt(value);
    for (int i = 0; i < lenOfValue; ++i) {
        printf("-");
    }
    printf("---------");
}


