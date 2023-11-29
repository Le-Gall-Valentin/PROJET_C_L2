//
// Created by hugol on 23/11/2023.
//

#include "Event.h"


void displayEvent(Event *event) {
    printf("%d/%d/%d at %d:%d, %d minutes long\n", event->day, event->month, event->year, event->hour, event->minutes,
           event->event_time);
    printf("%s\n", event->eventDescription);
}

StringArray requestDate() {
    char *newEntry;
    printf("enter new event (day/month/year hour/minutes time(minutes) description :");
    newEntry = scanString();
    StringArray event = splitStringToArray(newEntry, " ");
    return event;
}

Event *createEvent() {
    Event *newEvent = (Event *) malloc(sizeof(Event));

    char *newEntry;
    printf("enter new event (day/month/year hour/minutes time(minutes) :");
    newEntry = scanString();
    StringArray event = splitStringToArray(newEntry, " ");

    StringArray date = splitStringToArray(event.array[0], "/");
    newEvent->day = convertStringToDigit(date.array[0]);
    newEvent->month = convertStringToDigit(date.array[1]);
    newEvent->year = convertStringToDigit(date.array[2]);

    StringArray hour = splitStringToArray(event.array[1], "/");
    newEvent->hour = convertStringToDigit(hour.array[0]);
    newEvent->minutes = convertStringToDigit(hour.array[1]);

    newEvent->event_time = convertStringToDigit(event.array[2]);

    printf("Add Description :");
    newEvent->eventDescription = scanString();
    newEvent->next = NULL;
    return newEvent;
}