//
// Created by hugol on 23/11/2023.
//

#include "Contact.h"

Contact *entryOfContact() {
    // initialise le nom d'un contact
    char *name;
    Contact *contact;
    printf("insert lastname_firstname :");
    name = scanString();
    //lance la fonction pour initialiser un contact
    contact = createContact(name);
    return contact;
};


Contact *createContact(char *name) {
    
    for (int i = 0; i < strlen(name); ++i) {
        if (name[i] == ' ') {
            name[i] = '_';
        }
    }
    Contact *newContact = (Contact *) malloc(sizeof(Contact));
    newContact->lastnameFirstname = (char *) malloc(MAX_BUFFER * sizeof(char));
    strcpy(newContact->lastnameFirstname, name);
    //met le nom en minuscule
    toLowerCase(newContact->lastnameFirstname);
    newContact->listOfEvent = NULL;
    return newContact;
}


void displayContact(Contact *contact) {
    // affiche le contact
    printf("%s \n", contact->lastnameFirstname);
    displayListOfEvents(contact->listOfEvent);
}

void addEventToContact(Contact *contact) {
    // ajoute un event à la liste chainé d'évènnement 
    Event *newEventToAdd = createEvent();
    if (contact->listOfEvent == NULL) {
        contact->listOfEvent = newEventToAdd;
    } else {
        Event *temporaryEvent = contact->listOfEvent;
        while (temporaryEvent->next != NULL) {
            temporaryEvent = temporaryEvent->next;
        }
        temporaryEvent->next = newEventToAdd;
    }
}




