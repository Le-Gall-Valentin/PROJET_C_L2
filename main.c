#include <stdio.h>
#include "ListOfFloorCells.h"

int main() {
    ListOfFloorCells *myList = createEmptyFloorList(5);
    addHeadIntFloorList(myList, 12, 3);
    addHeadCharFloorList(myList, 'a', 2);
    addHeadStringFloorList(myList, "HEY", 2);
    addHeadStringFloorList(myList, "test25", 5);
    displayFloorList(myList);
    return 0;
}
