//
// Created by hugol on 23/11/2023.
//

#include "Event.h"


void addEventInList(Event **eventList, Event *event) {
    //ajoute un évennement à une liste chainée d'événement
    if (*eventList == NULL) {
        *eventList = event;
    } else {
        Event *temporaryEvent = *eventList;
        while (temporaryEvent->next != NULL) {
            temporaryEvent = temporaryEvent->next;
        }
        temporaryEvent->next = event;
    }
}

void displayEvent(Event *event) {
    //affiche les caractéristiques d'un événement
    printf("%d/%d/%d at %d:%d, %d minutes long\n", event->day, event->month, event->year, event->hour, event->minutes,
           event->event_time);
    printf("%s\n", event->eventDescription);
}

void displayListOfEvents(Event *list) {
    // Affiche tous les évènements d'une liste chainée d'événement 
    unsigned int eventId = 1;
    Event *temporaryEvent = list;
    while (temporaryEvent != NULL) {
        printf("Event ID = %d :\n", eventId);
        displayEvent(temporaryEvent);
        temporaryEvent = temporaryEvent->next;
        eventId++;
    }
}

void deleteEventInEventListWithId(Event **list, unsigned int ID) {
    // supprime un événement d'une liste chainé d'événement 
    Event *temporary = *list;
    Event *previous = NULL;
    if (*list != NULL) {
        //supprimer le premier évennement
        if (ID == 1) {
            *list = (*list)->next;
            free(temporary);
        } else {
            // parcours tant que nous ne sommes pas au bout de la liste d'événement ou que index != ID
            while (temporary != NULL && index != ID) {
                previous = temporary;
                temporary = temporary->next;
                index++;
            }
            if (temporary != NULL) {
                // il y a bien un événement avec l'ID alors on le supprime 
                previous->next = temporary->next;
                deleteEvent(temporary);
            }
        }
    }
}

void deleteEvent(Event *event) {
    free(event);
}

Event *createEvent() {
    // créé un nouvel événement et initialises toutes ses valeurs
    Event *newEvent = (Event *) malloc(sizeof(Event));

    char *newEntry;
    do {
        printf("enter new event (day/month/year hour/minutes time(minutes) :");
        newEntry = scanString();
    } while (newEntry == NULL);

    StringArray event = splitStringToArray(newEntry, " ");
    if (event.size != 3) {
        deleteString(event);
        deleteEvent(newEvent);
        printf("Error - ");
        createEvent();
    }
    StringArray date = splitStringToArray(event.array[0], "/");

    if (date.size != 3 || !isDigit(date.array[0]) || !isDigit(date.array[1]) || !isDigit(date.array[2])) {
        deleteString(event);
        deleteString(date);
        deleteEvent(newEvent);
        printf("Error - ");
        createEvent();
    }
    newEvent->day = convertStringToDigit(date.array[0]);
    newEvent->month = convertStringToDigit(date.array[1]);
    newEvent->year = convertStringToDigit(date.array[2]);
    deleteString(date);

    StringArray hour = splitStringToArray(event.array[1], "/");
    if (hour.size != 2 || !isDigit(hour.array[0]) || !isDigit(hour.array[1])) {
        deleteString(hour);
        deleteString(event);
        deleteEvent(newEvent);
        printf("Error - ");
        createEvent();
    }
    newEvent->hour = convertStringToDigit(hour.array[0]);
    newEvent->minutes = convertStringToDigit(hour.array[1]);
    deleteString(hour);

    if (!isDigit(event.array[2])) {
        deleteString(event);
        deleteEvent(newEvent);
        printf("Error - ");
        createEvent();
    }
    newEvent->event_time = convertStringToDigit(event.array[2]);
    deleteString(event);

    do {
        printf("Add Description :");
        newEvent->eventDescription = scanString();
    } while (newEvent->eventDescription == NULL);
    newEvent->next = NULL;
    return newEvent;
}

Event *createEmptyEvent() {
    // initialise un événement nul
    Event *newEvent = (Event *) malloc(sizeof(Event));
    newEvent->next = NULL;
    return newEvent;
}
