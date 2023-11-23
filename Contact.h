//
// Created by hugol on 23/11/2023.
//

#ifndef PROJET_C_L2_3_CONTACT_H
#define PROJET_C_L2_3_CONTACT_H
#include "Event.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "String functions.h"

typedef struct contact{
    char* lastnameFirstname;
    Event* listOfEvent;
 } Contact;

void addEventToContact(Contact* contact);
void displayContact(Contact contact);
Event *createEmptyListOfEvent();
Contact *createContact();
void displayListOfEvent();
#endif //PROJET_C_L2_3_CONTACT_H
