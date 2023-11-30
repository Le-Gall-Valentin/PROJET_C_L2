#include "Contact.h"
#include "ListOfFloorCells.h"
#include "manageCommands.h"

int main() {
//    ListOfFloorCells *myList = createEmptyFloorList(4);
//    Contact *contact1 = entryOfContact();
//    Contact *contact2 = entryOfContact();
//    Contact *contact3 = entryOfContact();
//    addEventToContact(contact3);
//    Contact *contact4 = entryOfContact();
//    Contact *contact5 = entryOfContact();
//    Contact *contact6 = entryOfContact();
//    Contact *contact7 = entryOfContact();
//    Contact *contact8 = entryOfContact();
//    addSortedCellInFloorList(myList, contact1);
//    printf("\n");
//    displayFloorList(myList);
//    addSortedCellInFloorList(myList, contact2);
//    printf("\n");
//    displayFloorList(myList);
//    addSortedCellInFloorList(myList, contact3);
//    printf("\n");
//    displayFloorList(myList);
//    addSortedCellInFloorList(myList, contact4);
//    printf("\n");
//    displayFloorList(myList);
//    addSortedCellInFloorList(myList, contact5);
//    printf("\n");
//    displayFloorList(myList);
//    addSortedCellInFloorList(myList, contact6);
//    printf("\n");
//    displayFloorList(myList);
//    addSortedCellInFloorList(myList, contact7);
//    printf("\n");
//    displayFloorList(myList);
//    addSortedCellInFloorList(myList, contact8);
//    printf("\n");
//    displayFloorList(myList);
//    printf("\n");
//    FloorCell *search = classicSearchValueInFloorList(myList, "garnier");
//    displayFloorCellAllInformations(search);
    int state = 1;
    ListOfFloorCells *agenda = createEmptyFloorList(4);
    while (state) {
        char *entry;
        printf(">");
        entry = scanString();
        makeCommand(entry, &state, agenda);
    }
    return 0;
}
