//
// Created by hugol on 23/11/2023.
//

#include "Event.h"


void displayEvent(Event *event) {
    printf("%d/%d/%d at %d:%d, %d minutes long\n", event->day, event->month, event->year, event->hour, event->minutes,
           event->event_time);
    printf("%s\n", event->eventDescription);
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
    deleteString(date);

    StringArray hour = splitStringToArray(event.array[1], "/");
    newEvent->hour = convertStringToDigit(hour.array[0]);
    newEvent->minutes = convertStringToDigit(hour.array[1]);
    deleteString(hour);

    newEvent->event_time = convertStringToDigit(event.array[2]);
    deleteString(event);

    printf("Add Description :");
    newEvent->eventDescription = scanString();
    newEvent->next = NULL;
    return newEvent;
}