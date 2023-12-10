#include <stdio.h>
#include "ListOfFloorCells.h"

int main() {
    ListOfFloorCells *myList = createEmptyFloorList(5);
    addSortedCellInFloorList(myList, 18, 4);
    addSortedCellInFloorList(myList, 25, 1);
    addSortedCellInFloorList(myList, 31, 2);
    addSortedCellInFloorList(myList, 32, 5);
    addSortedCellInFloorList(myList, 56, 3);
    addSortedCellInFloorList(myList, 59, 1);
    addSortedCellInFloorList(myList, 59, 5);
    addSortedCellInFloorList(myList, 91, 3);
    displayOneFloorOfFloorList(myList, 0);
    displayOneFloorOfFloorList(myList, 1);
    displayOneFloorOfFloorList(myList, 2);
    displayOneFloorOfFloorList(myList, 3);
    printf("\n");
    displayOneFloorOfFloorList(myList, 4);
    displayFloorList(myList);
    deleteFloorList(myList);
    return 0;
}
