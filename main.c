#include <stdio.h>
#include "ListOfFloorCells.h"
#include "timer.h"
#include "string.h"
#include "Contact.h"
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

    Contact *contact;
    contact = createContact();
    displayContact(*contact);
//    addEventToContact(contact);
//    displayContact(*contact);
//    addEventToContact(contact);
//    displayContact(*contact);
//    printf("%d",'a'-'A');
    return 0;
}
