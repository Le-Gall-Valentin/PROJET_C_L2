//
// Created by hugol on 23/11/2023.
//

#include "Contact.h"

Contact *entryOfContact() {
    char *name;
    Contact *contact;
    do {
        printf("insert lastname_firstname :");
        name = scanString();
    } while (name == NULL);
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
    toLowerCase(newContact->lastnameFirstname);
    newContact->listOfEvent = NULL;
    return newContact;
}


void displayContact(Contact *contact) {
    printf("%s \n", contact->lastnameFirstname);
    displayListOfEvents(contact->listOfEvent);
}

void addEventToContact(Contact *contact) {
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




