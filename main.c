#include "Contact.h"
#include "ListOfFloorCells.h"

int main() {
    ListOfFloorCells *myList = createEmptyFloorList(4);
    Contact *contact1 = entryOfContact();
    Contact *contact2 = entryOfContact();
    Contact *contact3 = entryOfContact();
    Contact *contact4 = entryOfContact();
    addContact(myList, contact1);
    addContact(myList, contact2);
    addContact(myList, contact3);
    addContact(myList, contact4);
    displayFloorList(myList);
    return 0;
}
