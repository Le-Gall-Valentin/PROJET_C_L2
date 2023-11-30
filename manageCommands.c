//
// Created by Le Gall on 29/11/2023.
//

#include "manageCommands.h"


void makeCommand(char *command, int *state, ListOfFloorCells *agenda) {
    printf("\n");
    toLowerCase(command);
    if (strcmp(command, "help") == 0) {
        help();
    } else if (strcmp(command, "viewcontact") == 0) {
        viewContact(agenda);
    } else if (strcmp(command, "createcontact") == 0) {
        addSortedCellInFloorList(agenda, entryOfContact());
    } else if (strcmp(command, "addnewmeet") == 0) {
        addNewMeet(agenda);
    } else if (strcmp(command, "viewallcontacts") == 0) {
        displayAllValues(agenda);
    } else if (strcmp(command, "exit") == 0) {
        printf("Good Bye !");
        *state = 0;
    } else {
        printf("Wrong command : use >help to view all commands\n");
    }
    printf("\n");
}

void viewContact(ListOfFloorCells *agenda) {
    printf("Entry name : ");
    char *name = scanString();
    toLowerCase(name);
    FloorCell *CellOfContact = classicSearchValueInFloorList(agenda, name);
    if (CellOfContact != NULL) {
        displayContact(CellOfContact->value);
    } else {
        printf("Contact doesn't exist ! create him");
    }
}

void addNewMeet(ListOfFloorCells *agenda) {
    printf("Entry name : ");
    char *name = scanString();
    toLowerCase(name);
    FloorCell *CellOfContact = classicSearchValueInFloorList(agenda, name);
    if (CellOfContact != NULL) {
        printf("Contact exists - ");
        addEventToContact(CellOfContact->value);
    } else {
        Contact *newContact = createContact(name);
        addSortedCellInFloorList(agenda, newContact);
        printf("Contact doesn't exist but he is add to agenda - ");
        addEventToContact(newContact);
    }
}

void help() {
    printf("viewContact\n");
    printf("viewAllContacts\n");
    printf("searchContact \n");
    printf("createContact \n");
    printf("addNewMeet\n");
    printf("deleteMeet\n");
    printf("exit\n");
}
