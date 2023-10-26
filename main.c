#include <stdio.h>
#include "ListOfFloorCells.h"

int main() {
    ListOfFloorCells *myList = createEmptyFloorList(5);
    addHeadFloorList(myList, 91, 3);
    addHeadFloorList(myList, 59, 1);
    addHeadFloorList(myList, 59, 4);
    addHeadFloorList(myList, 56, 3);
    addHeadFloorList(myList, 32, 5);
    addHeadFloorList(myList, 31, 2);
    addHeadFloorList(myList, 25, 1);
    addHeadFloorList(myList, 18, 4);
    printf("%d",myList->ArrayOfCell[3]->arrayOfNexts[1]->value);
//    displayFloorList(myList);
    return 0;
}
