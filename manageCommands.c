//
// Created by Le Gall on 29/11/2023.
//

#include "manageCommands.h"


void makeCommand(char *command, unsigned short *state, unsigned short *autoComplete, ListOfFloorCells *agenda) {
    // Gestions des commandes du menu
    printf("\n");
    toLowerCase(command);
    if (strcmp(command, "help") == 0) {
        help();
    } else if (strcmp(command, "viewcontact") == 0) {
        viewContact(agenda, *autoComplete);
    } else if (strcmp(command, "createcontact") == 0) {
        addSortedCellInFloorList(agenda, entryOfContact());
    } else if (strcmp(command, "addnewmeet") == 0) {
        addNewMeet(agenda, *autoComplete);
    } else if (strcmp(command, "deletemeet") == 0) {
        deleteMeet(agenda, *autoComplete);
    } else if (strcmp(command, "viewallcontacts") == 0) {
        displayAllValues(agenda);
    } else if (strcmp(command, "exit") == 0) {
        printf("Good Bye !");
        *state = 0;
    } else if (strcmp(command, "loadagenda") == 0) {
        loadAgenda(agenda);
    } else if (strcmp(command, "saveagenda") == 0) {
        saveAgenda(agenda);
    } else if (strcmp(command, "adminviewlist") == 0) {
        displayFloorList(agenda);
    } else if (strcmp(command, "autocomplete") == 0) {
        changeAutoComplete(autoComplete);
    } else {
        printf("Wrong command : use >help to view all commands\n");
    }
    printf("\n");
}

FloorCell *searchInAgendaWithAutoCompletion(ListOfFloorCells *agenda, unsigned short autoComplete, char **name) {

    // Fonction D'auto complétion qui peut etre activé ou non. La fonction affiche toutes les nom qui commencent par la premieres lettres et ainsi de suite pour les 4 premières lettres
    char *newName;
    char *letter = NULL;
    if (autoComplete == 0) {
        do {
            printf("Entry name :");
            newName = scanString();
        } while (newName == NULL);
        toLowerCase(newName);
        if (name != NULL) {
            *name = newName;
        }
        return levelSearchValueInFloorList(agenda, newName);
    } else {
        FloorCell *temporary = agenda->ArrayOfCell[3];
        FloorCell *previous = NULL;
        if (temporary != NULL) {
            for (int level = 3; level >= 0; --level) {
                char temporaryLetter = -1;
                unsigned short stop = 0;
                printf("Lettres possibles pour le niveau %d : ", level);
                while (temporary != NULL && stop == 0) {
                    if (temporary->value->lastnameFirstname[3 - level] != temporaryLetter) {
                        printf("%c ", temporary->value->lastnameFirstname[3 - level]);
                        temporaryLetter = temporary->value->lastnameFirstname[3 - level];
                    }
                    temporary = temporary->arrayOfNexts[level];
                    if (temporary != NULL && temporary->nbFloors > level + 1) {
                        stop = 1;
                    }
                }
                printf("\n");
                do {
                    do {
                        printf("Entrer la lettre pour le niveau %d :", level);
                        letter = scanString();
                        toLowerCase(letter);
                    } while (letter == NULL || ((strlen(letter) != 1) || isDigit(letter)));
                    if (previous == NULL) {
                        temporary = agenda->ArrayOfCell[level];
                    } else {
                        temporary = previous;
                    }
                    while (temporary != NULL && temporary->value->lastnameFirstname[3 - level] != letter[0]) {
                        temporary = temporary->arrayOfNexts[level];
                        previous = temporary;
                    }
                } while (temporary == NULL);
            }


            unsigned short stop = 0;
            printf("noms possibles : ");
            while (temporary != NULL && stop == 0) {
                if (temporary->value->lastnameFirstname[3] == letter[0]) {
                    printf("%s ", temporary->value->lastnameFirstname);
                    temporary = temporary->arrayOfNexts[0];
                    if ((temporary != NULL && temporary->nbFloors > 1)) {
                        stop = 1;
                    }
                } else {
                    stop = 1;
                }
            }
            printf("\n");


            printf("Entry name :");
            newName = scanString();
            toLowerCase(newName);
            if (name != NULL) {
                *name = newName;
            }
            return levelSearchValueInFloorList(agenda, newName);
        }
        return NULL;
    }
}

void changeAutoComplete(unsigned short *autoComplete) {
    if (*autoComplete == 0) {
        *autoComplete = 1;
        printf("auto complete is now active\n");
    } else {
        *autoComplete = 0;
        printf("auto complete is now inactive\n");
    }
}

void deleteMeet(ListOfFloorCells *agenda, unsigned short autoComplete) {
    FloorCell *CellOfContact = searchInAgendaWithAutoCompletion(agenda, autoComplete, NULL);
    if (CellOfContact != NULL) {
        char *eventID;
        do {
            printf("Entry event ID :");
            eventID = scanString();
        } while (!isDigit(eventID) || convertStringToDigit(eventID) < 1);
        deleteEventInEventListWithId(&(CellOfContact->value->listOfEvent), convertStringToDigit(eventID));
    } else {
        printf("Contact doesn't exist ! create him");
    }
}

void viewContact(ListOfFloorCells *agenda, unsigned short autoComplete) {
    FloorCell *CellOfContact = searchInAgendaWithAutoCompletion(agenda, autoComplete, NULL);
    if (CellOfContact != NULL) {
        displayContact(CellOfContact->value);
    } else {
        printf("Contact doesn't exist ! create him");
    }
}

void addNewMeet(ListOfFloorCells *agenda, unsigned short autoComplete) {
    char *name;
    FloorCell *CellOfContact = searchInAgendaWithAutoCompletion(agenda, autoComplete, &name);
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
    printf("createContact \n");
    printf("addNewMeet\n");
    printf("deleteMeet\n");
    printf("saveAgenda\n");
    printf("loadAgenda\n");
    printf("autoComplete\n");
    printf("exit\n");
}
