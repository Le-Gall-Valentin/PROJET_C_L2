//
// Created by hugol on 23/11/2023.
//

#ifndef PROJET_C_L2_3_EVENT_H
#define PROJET_C_L2_3_EVENT_H

#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "manageString.h"

typedef struct event {
    int day, month, year, hour, minutes, event_time;
    char *eventDescription;
    struct event *next;
} Event;

void displayListOfEvents(Event *list);

void displayEvent(Event *);

Event *createEvent();

void deleteEvent(Event *event);

void deleteEventInEventListWithId(Event **list, unsigned int ID);

#endif //PROJET_C_L2_3_EVENT_H
