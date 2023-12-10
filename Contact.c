//
// Created by hugol on 23/11/2023.
//

#include "Contact.h"

Contact *entryOfContact() {
    char *name;
    Contact *contact;

    // Demande à l'utilisateur d'entrer le nom et prénom
    do {
        printf("Insert lastname_firstname: ");
        name = scanString();
    } while (name == NULL);

    // Crée une structure Contact avec le nom et prénom fournis
    contact = createContact(name);

    // Retourne le contact créé
    return contact;
}


Contact *createContact(char *name) {
    // Remplace les espaces par des underscores dans le nom
    for (int i = 0; i < strlen(name); ++i) {
        if (name[i] == ' ') {
            name[i] = '_';
        }
    }

    // Alloue de la mémoire pour la nouvelle structure Contact
    Contact *newContact = (Contact *) malloc(sizeof(Contact));

    // Alloue de la mémoire pour la chaîne lastnameFirstname
    newContact->lastnameFirstname = (char *) malloc(MAX_BUFFER * sizeof(char));

    // Copie le nom traité dans lastnameFirstname
    strcpy(newContact->lastnameFirstname, name);

    // Convertit la chaîne en minuscules
    toLowerCase(newContact->lastnameFirstname);

    // Initialise la liste d'événements à NULL
    newContact->listOfEvent = NULL;

    // Retourne le nouveau contact créé
    return newContact;
}


void displayContact(Contact *contact) {
    // Affiche le nom et prénom du contact
    printf("%s \n", contact->lastnameFirstname);

    // Affiche la liste d'événements associée au contact
    displayListOfEvents(contact->listOfEvent);
}


void addEventToContact(Contact *contact) {
    // Crée un nouvel événement en demandant à l'utilisateur de saisir ses détails
    Event *newEventToAdd = createEvent();

    // Si la liste d'événements du contact est vide, le nouvel événement devient le premier de la liste
    if (contact->listOfEvent == NULL) {
        contact->listOfEvent = newEventToAdd;
    } else {
        // Sinon, ajoute le nouvel événement à la fin de la liste
        Event *temporaryEvent = contact->listOfEvent;
        while (temporaryEvent->next != NULL) {
            temporaryEvent = temporaryEvent->next;
        }
        temporaryEvent->next = newEventToAdd;
    }
}





