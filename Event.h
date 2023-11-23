//
// Created by hugol on 23/11/2023.
//

#ifndef PROJET_C_L2_3_EVENT_H
#define PROJET_C_L2_3_EVENT_H
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "String functions.h"

typedef struct event{
    int day,month,year,hour,minutes,event_time;
    char* eventDescription;
    struct event *next;
}Event;


void displayEvent(Event*);
Event *createEvent();
#endif //PROJET_C_L2_3_EVENT_H
