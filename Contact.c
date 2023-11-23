//
// Created by hugol on 23/11/2023.
//

#include "Contact.h"


void toLowerCase(char *firstname);

Contact *createContact(){
    Contact *newContact = (Contact*) malloc(sizeof (Contact));
    printf("insert lastname_firstname\n");
    newContact->lastnameFirstname = scanString();
    toLowerCase(newContact->lastnameFirstname);
    newContact->listOfEvent = NULL;
    return newContact;
}

void toLowerCase(char *name) {
    unsigned long long size = strlen(name);
    for(int i=0; i<size;i++){
        if(name[i]<='Z' && name[i] != '_'){
            name[i] = name[i]+32;
        }
    }
}

void displayContact(Contact contact){
    printf("%s",contact.lastnameFirstname);
    displayListOfEvent(contact.listOfEvent);
}

void displayListOfEvent(Event* list) {
    Event *temporaryEvent = list;
    while (temporaryEvent != NULL){
        displayEvent(temporaryEvent);
        temporaryEvent = temporaryEvent->next;
    }
}

void addEventToContact(Contact* contact){
    Event* newEventToAdd = createEvent();
    if(contact->listOfEvent == NULL){
        contact->listOfEvent = newEventToAdd;
    }else{
        Event *temporaryEvent = contact->listOfEvent;
        while (temporaryEvent->next!=NULL){
            temporaryEvent = temporaryEvent->next;
        }
        temporaryEvent->next = newEventToAdd;
    }
}




