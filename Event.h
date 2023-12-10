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
    int day;             // Jour de l'événement
    int month;           // Mois de l'événement
    int year;            // Année de l'événement
    int hour;            // Heure de l'événement
    int minutes;         // Minutes de l'événement
    int event_time;      // Temps de l'événement
    char *eventDescription;  // Description de l'événement
    struct event *next;  // Pointeur vers le prochain événement dans la liste chaînée
} Event;

void displayListOfEvents(Event *list);

void displayEvent(Event *);

Event *createEvent();

void deleteEvent(Event *event);

void deleteEventInEventListWithId(Event **list, unsigned int ID);

Event *createEmptyEvent();

void addEventInList(Event **eventList, Event *event);

#endif //PROJET_C_L2_3_EVENT_H
