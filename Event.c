//
// Created by hugol on 23/11/2023.
//

#include "Event.h"


void displayEvent(Event *event) {
    printf("%d/%d/%d at %d:%d, %d minutes long\n", event->day, event->month, event->year, event->hour, event->minutes,
           event->event_time);
    printf("%s\n", event->eventDescription);
}

void displayListOfEvents(Event *list) {
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
    Event *temporary = *list;
    Event *previous = NULL;
    if (*list != NULL) {
        if (ID == 1) {
            *list = (*list)->next;
            free(temporary);
        } else {
            unsigned int index = 1;
            while (temporary != NULL && index != ID) {
                previous = temporary;
                temporary = temporary->next;
                index++;
            }
            if (temporary != NULL) {
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
    Event *newEvent = (Event *) malloc(sizeof(Event));

    char *newEntry;
    printf("enter new event (day/month/year hour/minutes time(minutes) :");
    newEntry = scanString();
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

    printf("Add Description :");
    newEvent->eventDescription = scanString();
    newEvent->next = NULL;
    return newEvent;
}