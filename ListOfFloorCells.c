//
// Created by Le Gall on 26/10/2023.
//

#include "ListOfFloorCells.h"

ListOfFloorCells *createEmptyFloorList(int nbFloors) {
    ListOfFloorCells *newFloorList = (ListOfFloorCells *) malloc(sizeof(ListOfFloorCells));
    newFloorList->ArrayOfCell = createArrayOfNexts(nbFloors);
    newFloorList->nbFloors = nbFloors;
    return newFloorList;
}

void addHeadIntFloorList(ListOfFloorCells *list, int value, int nbFloors){
    addHeadFloorList(list, (void*) createIntegerStruct(value), integer, nbFloors);
}

void addHeadCharFloorList(ListOfFloorCells *list, char value, int nbFloors){
    addHeadFloorList(list, (void*) createCharStruct(value), character, nbFloors);
}

void addHeadStringFloorList(ListOfFloorCells *list, char* value, int nbFloors){
    addHeadFloorList(list, (void*) createStringStruct(value), string, nbFloors);
}

void addHeadFloorList(ListOfFloorCells *list, void* value, allTypes type, int nbFloors) {
    FloorCell *newCell = createFloorCell(value, type, nbFloors);
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
                displayGap(temporaryCellFloor0);
            }
            temporaryCellFloor0 = temporaryCellFloor0->arrayOfNexts[0];
        }
        printf("--> NULL\n");
    }
}




