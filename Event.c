//
// Created by hugol on 23/11/2023.
//

#include "Event.h"


void addEventInList(Event **eventList, Event *event) {
    // Si la liste est vide, le nouvel événement devient le premier de la liste
    if (*eventList == NULL) {
        *eventList = event;
    } else {
        // Si la liste n'est pas vide, recherche le dernier événement
        Event *temporaryEvent = *eventList;
        while (temporaryEvent->next != NULL) {
            temporaryEvent = temporaryEvent->next;
        }
        // Ajoute le nouvel événement à la fin de la liste
        temporaryEvent->next = event;
    }
}

void displayEvent(Event *event) {
    // Affiche les détails de l'événement
    printf("%d/%d/%d at %d:%d, %d minutes long\n", event->day, event->month, event->year, event->hour, event->minutes,
           event->event_time);
    printf("%s\n", event->eventDescription);
}


void displayListOfEvents(Event *list) {
    // Identifiant unique pour chaque événement
    unsigned int eventId = 1;

    // Pointeur temporaire pour parcourir la liste d'événements
    Event *temporaryEvent = list;

    // Parcours de la liste d'événements
    while (temporaryEvent != NULL) {
        // Affichage de l'identifiant de l'événement
        printf("Event ID = %d :\n", eventId);

        // Affichage des détails de l'événement en utilisant la fonction displayEvent
        displayEvent(temporaryEvent);

        // Avance vers le prochain événement dans la liste
        temporaryEvent = temporaryEvent->next;

        // Incrémente l'identifiant de l'événement
        eventId++;
    }
}

void deleteEventInEventListWithId(Event **list, unsigned int ID) {
    // Pointeur temporaire pour parcourir la liste d'événements
    Event *temporary = *list;

    // Pointeur vers l'événement précédent
    Event *previous = NULL;

    // Vérifie si la liste n'est pas vide
    if (*list != NULL) {
        // Vérifie si l'événement à supprimer est le premier de la liste
        if (ID == 1) {
            *list = (*list)->next; // Met à jour la tête de liste
            free(temporary); // Libère la mémoire de l'événement supprimé
        } else {
            // Recherche de l'événement à supprimer
            unsigned int index = 1;
            while (temporary != NULL && index != ID) {
                previous = temporary;
                temporary = temporary->next;
                index++;
            }

            // Vérifie si l'événement à supprimer a été trouvé
            if (temporary != NULL) {
                // Met à jour les pointeurs pour sauter l'événement à supprimer
                previous->next = temporary->next;

                // Libère la mémoire de l'événement supprimé
                deleteEvent(temporary);
            }
        }
    }
}


void deleteEvent(Event *event) {
    // Libère la mémoire allouée pour la description de l'événement
    free(event->eventDescription);

    // Libère la mémoire allouée pour la structure de l'événement
    free(event);
}


Event *createEvent() {
    // Alloue de la mémoire pour la nouvelle structure d'événement
    Event *newEvent = (Event *) malloc(sizeof(Event));

    // Demande à l'utilisateur d'entrer les détails de l'événement
    char *newEntry;
    do {
        printf("Enter new event (day/month/year hour/minutes time(minutes)): ");
        newEntry = scanString();
    } while (newEntry == NULL);

    // Utilise une structure StringArray pour traiter l'entrée de manière plus flexible
    StringArray event = splitStringToArray(newEntry, " ");
    if (event.size != 3 || !isDigit(event.array[2])) {
        // Gestion des erreurs lors de la saisie des détails de l'événement
        printf("Error - Invalid input. Please try again.\n");
        deleteString(event);
        free(newEvent);
        return createEvent(); // Appel récursif pour une nouvelle saisie
    }

    // Gestion de la date
    StringArray date = splitStringToArray(event.array[0], "/");
    if (date.size != 3 || !isDigit(date.array[0]) || !isDigit(date.array[1]) || !isDigit(date.array[2])) {
        printf("Error - Invalid date format. Please try again.\n");
        deleteString(event);
        deleteString(date);
        free(newEvent);
        return createEvent();
    }
    newEvent->day = convertStringToDigit(date.array[0]);
    newEvent->month = convertStringToDigit(date.array[1]);
    newEvent->year = convertStringToDigit(date.array[2]);
    deleteString(date);

    // Gestion de l'heure
    StringArray hour = splitStringToArray(event.array[1], "/");
    if (hour.size != 2 || !isDigit(hour.array[0]) || !isDigit(hour.array[1])) {
        printf("Error - Invalid time format. Please try again.\n");
        deleteString(event);
        deleteString(hour);
        free(newEvent);
        return createEvent();
    }
    newEvent->hour = convertStringToDigit(hour.array[0]);
    newEvent->minutes = convertStringToDigit(hour.array[1]);
    deleteString(hour);

    // Gestion de la durée de l'événement
    newEvent->event_time = convertStringToDigit(event.array[2]);

    // Demande à l'utilisateur d'ajouter une description
    do {
        printf("Add Description: ");
        newEvent->eventDescription = scanString();
    } while (newEvent->eventDescription == NULL);

    // Initialise le pointeur suivant à NULL
    newEvent->next = NULL;

    // Libère la mémoire utilisée par l'entrée de l'utilisateur
    deleteString(event);

    // Retourne le nouvel événement créé
    return newEvent;
}


Event *createEmptyEvent() {
    // Alloue de la mémoire pour la nouvelle structure d'événement
    Event *newEvent = (Event *) malloc(sizeof(Event));

    // Initialise le pointeur suivant à NULL (la liste est vide)
    newEvent->next = NULL;

    // Retourne le nouvel événement vide
    return newEvent;
}
