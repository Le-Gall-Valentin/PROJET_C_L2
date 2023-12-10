//
// Created by hugol on 23/11/2023.
//

#ifndef PROJET_C_L2_3_CONTACT_H
#define PROJET_C_L2_3_CONTACT_H
#define MAX_BUFFER 100

#include "Event.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "manageString.h"

typedef struct contact {
    char *lastnameFirstname;  // Nom et prénom du contact
    Event *listOfEvent;        // Liste d'événements associés au contact
} Contact;

void addEventToContact(Contact *contact);

void displayContact(Contact *contact);

Contact *entryOfContact();

Contact *createContact(char *name);

#endif //PROJET_C_L2_3_CONTACT_H
