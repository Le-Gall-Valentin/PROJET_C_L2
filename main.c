#include <stdio.h>
#include "ListOfFloorCells.h"
#include "timer.h"
#include "string.h"

int main() {
//    srand(time(NULL));
//    for (int i = 1; i <= 25; ++i) {
//        FILE *f = freopen("classic2.txt", "a", stdout);
//        ListOfFloorCells *myList = createSortedListWithNValues(i);
//        printf("%d; ", i);
//
//        startTimer();
//        for (int j = 0; j < 10000; ++j) {
//            unsigned long long searchValue = (getLongRandomNumber() % (((unsigned long long) pow(2, i)) - 1)) + 1;
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
//            unsigned long long searchValue = (getLongRandomNumber() % (((unsigned long long) pow(2, i)) - 1)) + 1;
//            levelSearchValueInFloorList(myList, searchValue);
//        }
//        stopTimer();
//        stopTimer();
//        printf("%s\n", getTimeAsString());
//        fclose(f2);
//        deleteFloorList(myList);
//    }
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
    displayOneFloorOfFloorList(myList, 4);
    printf("\n");
    displayFloorList(myList);
    return 0;
}
