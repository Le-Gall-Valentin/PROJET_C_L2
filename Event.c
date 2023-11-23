//
// Created by hugol on 23/11/2023.
//

#include "Event.h"


void displayEvent(Event* event){
    printf("\n%d/%d/%d at %d:%d, %d minutes long",event->day, event->month,event->year,event->hour,event->minutes,event->event_time);
    printf("\n%s",event->eventDescription);
}

Event *createEvent(){
    Event *newEvent = (Event*) malloc(sizeof (Event));
    printf("enter date : day mont year :\n");
    scanf("%d %d %d",&newEvent->day,&newEvent->month,&newEvent->year);
    printf("enter the hour were the event will take place :\n");
    scanf("%d %d",&newEvent->hour,&newEvent->minutes);
    printf("How many time did the event will take :\n");
    scanf("%d",&newEvent->event_time);
    printf("describe the event :\n");
    fflush(stdin);
    newEvent->eventDescription = scanString();
    newEvent->next = NULL;
    return newEvent;
}