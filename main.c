#include <stdio.h>
#include "ListOfFloorCells.h"
#include "timer.h"
#include "string.h"

int main() {
//    srand (time (NULL));
//    for (int i = 7; i <= 20; ++i) {
//        FILE *f = freopen("classic2.txt", "a", stdout);
//        ListOfFloorCells *myList = createSortedListWithNValues(i);
//        printf("%d; ", i);
//
//        startTimer();
//        for (int j = 0; j < 10000; ++j) {
//            int searchValue = rand();
//            classicSearchValueInFloorList(myList, searchValue);
//        }
//        stopTimer();
//        printf("%s\n", getTimeAsString());
//        fclose(f);
//
//        FILE *f2 = freopen("levels2.txt", "a", stdout);
//        printf("%d; ", i);
//
//        startTimer();
//        for (int j = 0; j < 10000; ++j) {
//            int searchValue = rand();
//            levelSearchValueInFloorList(myList, searchValue);
//        }stopTimer();
//        stopTimer();
//        printf("%s\n", getTimeAsString());
//        fclose(f2);
////        deleteFloorList(myList);
//    }
    ListOfFloorCells *myList = createEmptyFloorList(5);
    addSortedCellInFloorList(myList,3,2);
    addSortedCellInFloorList(myList,9,1);
    addSortedCellInFloorList(myList,8,4);
    addSortedCellInFloorList(myList,5,3);
    addSortedCellInFloorList(myList,6,2);
    addSortedCellInFloorList(myList,7,3);
    addSortedCellInFloorList(myList,1,5);
    displayFloorList(myList);
    return 0;
}
