//
// Created by Le Gall on 29/11/2023.
//

#include "manageCommands.h"


void makeCommand(char *command, unsigned short *state, unsigned short *autoComplete, ListOfFloorCells *agenda) {
    printf("\n");

    // Convertit la commande en minuscules pour rendre la comparaison insensible à la casse
    toLowerCase(command);

    // Compare la commande avec différentes options
    if (strcmp(command, "help") == 0) {
        help();
    } else if (strcmp(command, "viewcontact") == 0) {
        viewContact(agenda, *autoComplete);
    } else if (strcmp(command, "createcontact") == 0) {
        // Ajoute un nouveau contact à la liste triée
        addSortedCellInFloorList(agenda, entryOfContact());
    } else if (strcmp(command, "addnewmeet") == 0) {
        // Ajoute un nouveau rendez-vous
        addNewMeet(agenda, *autoComplete);
    } else if (strcmp(command, "deletemeet") == 0) {
        // Supprime un rendez-vous
        deleteMeet(agenda, *autoComplete);
    } else if (strcmp(command, "viewallcontacts") == 0) {
        // Affiche tous les noms dans la liste d'étages
        displayAllValues(agenda);
    } else if (strcmp(command, "exit") == 0) {
        // Termine l'application
        printf("Good Bye !");
        *state = 0;
    } else if (strcmp(command, "loadagenda") == 0) {
        // Charge l'agenda à partir d'un fichier
        loadAgenda(agenda);
    } else if (strcmp(command, "saveagenda") == 0) {
        // Enregistre l'agenda dans un fichier
        saveAgenda(agenda);
    } else if (strcmp(command, "adminviewlist") == 0) {
        // Affiche la liste d'étages (pour le mode administrateur)
        displayFloorList(agenda);
    } else if (strcmp(command, "autocomplete") == 0) {
        // Active/désactive la fonction d'auto-complétion
        changeAutoComplete(autoComplete);
    } else {
        // Affiche un message d'erreur pour une commande incorrecte
        printf("Wrong command : use >help to view all commands\n");
    }

    printf("\n");
}


FloorCell *searchInAgendaWithAutoCompletion(ListOfFloorCells *agenda, unsigned short autoComplete, char **name) {
    char *newName;
    char *letter = NULL;

    if (autoComplete == 0) {
        // Si l'auto-complétion est désactivée, demander simplement le nom
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

        // Parcourir les niveaux avec auto-complétion
        for (int level = 3; level >= 0; --level) {
            char temporaryLetter = -1;
            unsigned short stop = 0;
            printf("Possible letters for the level %d : ", level);

            // Afficher les lettres possibles pour le niveau
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

            // Demander à l'utilisateur de choisir une lettre
            do {
                do {
                    printf("Enter the letter for the level %d :", level);
                    letter = scanString();
                    toLowerCase(letter);
                } while (letter == NULL || ((strlen(letter) != 1) || isDigit(letter)));

                if (previous == NULL) {
                    temporary = agenda->ArrayOfCell[level];
                } else {
                    temporary = previous;
                }

                // Trouver la lettre dans la liste
                while (temporary != NULL && temporary->value->lastnameFirstname[3 - level] != letter[0]) {
                    temporary = temporary->arrayOfNexts[level];
                    previous = temporary;
                }
            } while (temporary == NULL);
        }

        unsigned short stop = 0;
        printf("possible names : ");

        // Afficher les noms possibles avec la lettre choisie
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

        // Demander le nom complet
        printf("Entry name :");
        newName = scanString();
        toLowerCase(newName);
        if (name != NULL) {
            *name = newName;
        }

        // Recherche dans la liste à l'aide du nom complet
        return levelSearchValueInFloorList(agenda, newName);
    }

    // Si aucune correspondance n'est trouvée
    return NULL;
}


void changeAutoComplete(unsigned short *autoComplete) {
    // Si l'auto-complétion est désactivée, l'activer, sinon la désactiver
    if (*autoComplete == 0) {
        *autoComplete = 1;
        printf("Auto-complete is now active.\n");
    } else {
        *autoComplete = 0;
        printf("Auto-complete is now inactive.\n");
    }
}


void deleteMeet(ListOfFloorCells *agenda, unsigned short autoComplete) {
    // Rechercher le contact dans l'agenda
    FloorCell *cellOfContact = searchInAgendaWithAutoCompletion(agenda, autoComplete, NULL);

    if (cellOfContact != NULL) {
        char *eventID;

        // Saisir l'ID de l'événement à supprimer
        do {
            printf("Enter event ID to delete: ");
            eventID = scanString();
        } while (!isDigit(eventID) || convertStringToDigit(eventID) < 1);

        // Supprimer l'événement avec l'ID spécifié
        deleteEventInEventListWithId(&(cellOfContact->value->listOfEvent), convertStringToDigit(eventID));
    } else {
        // Afficher un message si le contact n'existe pas
        printf("Contact doesn't exist! Create the contact first.\n");
    }
}


void viewContact(ListOfFloorCells *agenda, unsigned short autoComplete) {
    // Rechercher le contact dans l'agenda
    FloorCell *cellOfContact = searchInAgendaWithAutoCompletion(agenda, autoComplete, NULL);

    if (cellOfContact != NULL) {
        // Afficher les détails du contact
        displayContact(cellOfContact->value);
    } else {
        // Afficher un message si le contact n'existe pas
        printf("Contact doesn't exist! Create the contact first.\n");
    }
}


void addNewMeet(ListOfFloorCells *agenda, unsigned short autoComplete) {
    char *name;
    // Rechercher le contact dans l'agenda (éventuellement avec l'autocomplétion)
    FloorCell *cellOfContact = searchInAgendaWithAutoCompletion(agenda, autoComplete, &name);

    if (cellOfContact != NULL) {
        // Le contact existe, ajouter un nouvel événement
        printf("Contact exists - ");
        addEventToContact(cellOfContact->value);
    } else {
        // Le contact n'existe pas, créer un nouveau contact
        Contact *newContact = createContact(name);
        addSortedCellInFloorList(agenda, newContact);
        printf("Contact doesn't exist, but added to agenda - ");
        addEventToContact(newContact);
    }
}


void help() {
    printf("viewContact      : View details of a contact\n");
    printf("viewAllContacts  : View details of all contacts\n");
    printf("createContact    : Create a new contact\n");
    printf("addNewMeet       : Add a new meeting/event\n");
    printf("deleteMeet       : Delete a meeting/event\n");
    printf("saveAgenda       : Save the agenda to a file\n");
    printf("loadAgenda       : Load the agenda from a file\n");
    printf("autoComplete     : Toggle auto-completion feature\n");
    printf("exit             : Exit the program\n");
}
