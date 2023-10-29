#include <stdio.h>
#include "ListOfFloorCells.h"
#include "timer.h"
#include "string.h"

int main() {
    srand (time (NULL));
    char* timer = NULL;
    for (int i = 1; i <= 30; ++i) {
        FILE *f = freopen("classic.txt", "a", stdout);
        ListOfFloorCells *myList = createSortedListWithNValues(i);
        printf("%d; ", i);
        startTimer();
        for (int j = 0; j < 1000; ++j) {
            int searchValue = (rand() % ((int)pow(2, i)-1))+1;
            classicSearchValueInFloorList(myList, searchValue);
        }
        stopTimer();
        timer = getTimeAsString();
        printf("%s; ", timer);
        free(timer);

        startTimer();
        for (int j = 0; j < 10000; ++j) {
            int searchValue = (rand() % ((int)pow(2, i)-1))+1;
            classicSearchValueInFloorList(myList, searchValue);
        }
        stopTimer();
        timer = getTimeAsString();
        printf("%s; ", timer);
        free(timer);

        startTimer();
        for (int j = 0; j < 100000; ++j) {
            int searchValue = (rand() % ((int)pow(2, i)-1))+1;
            classicSearchValueInFloorList(myList, searchValue);
        }
        stopTimer();
        timer = getTimeAsString();
        printf("%s\n", timer);
        free(timer);
        fclose(f);

        FILE *f2 = freopen("levels.txt", "a", stdout);
        printf("%d; ", i);
        startTimer();
        for (int j = 0; j < 1000; ++j) {
            int searchValue = (rand() % ((int)pow(2, i)-1))+1;
            levelSearchValueInFloorList(myList, searchValue);
        }
        stopTimer();
        timer = getTimeAsString();
        printf("%s; ", timer);
        free(timer);

        startTimer();
        for (int j = 0; j < 10000; ++j) {
            int searchValue = (rand() % ((int)pow(2, i)-1))+1;
            levelSearchValueInFloorList(myList, searchValue);
        }
        stopTimer();
        timer = getTimeAsString();
        printf("%s; ", timer);
        free(timer);

        startTimer();
        for (int j = 0; j < 100000; ++j) {
            int searchValue = (rand() % ((int)pow(2, i)-1))+1;
            levelSearchValueInFloorList(myList, searchValue);
        }stopTimer();
        timer = getTimeAsString();
        printf("%s\n", timer);
        free(timer);
        fclose(f2);
    }

    return 0;
}
