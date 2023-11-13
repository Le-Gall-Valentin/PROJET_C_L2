#include <stdio.h>
#include "ListOfFloorCells.h"
#include "timer.h"
#include "string.h"

int main() {
    srand (time (NULL));
    for (int i = 1; i <= 25; ++i) {
        unsigned long long  searchValue = (unsigned long long)pow(2,i)-1;;
        FILE *f = freopen("classic2.txt", "a", stdout);
        ListOfFloorCells *myList = createSortedListWithNValues(i);
        printf("%d; ", i);

        startTimer();
        for (int j = 0; j < 10000; ++j) {
            classicSearchValueInFloorList(myList, searchValue);
        }
        stopTimer();
        printf("%s\n", getTimeAsString());
        fclose(f);

        FILE *f2 = freopen("levels2.txt", "a", stdout);
        printf("%d; ", i);

        startTimer();
        for (int j = 0; j < 10000; ++j) {
            levelSearchValueInFloorList(myList, searchValue);
        }stopTimer();
        stopTimer();
        printf("%s\n", getTimeAsString());
        fclose(f2);
//        deleteFloorList(myList);
    }
    return 0;
}
