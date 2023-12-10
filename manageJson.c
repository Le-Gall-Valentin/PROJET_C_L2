//
// Created by Le Gall on 03/12/2023.
//

#include "manageJson.h"

void saveAgenda(ListOfFloorCells *agenda) {
    FILE *fp;

    // Demander le nom du fichier jusqu'à ce qu'il puisse être ouvert avec succès
    do {
        printf("File name: ");
        char *fileName = scanString();
        fp = fopen(fileName, "w");
    } while (fp == NULL);

    // Écrire le début du fichier JSON
    fputs("{\n", fp);

    // Parcourir chaque contact dans l'agenda
    FloorCell *temporary = agenda->ArrayOfCell[0];
    while (temporary != NULL) {
        // Écrire le nom du contact comme clé
        fprintf(fp, "\"%s\": [\n", temporary->value->lastnameFirstname);

        // Parcourir chaque événement dans la liste d'événements du contact
        Event *temporaryEvent = temporary->value->listOfEvent;
        while (temporaryEvent != NULL) {
            // Écrire les détails de l'événement
            fprintf(fp, "{\"Date\": \"%d/%d/%d\",\n", temporaryEvent->day, temporaryEvent->month, temporaryEvent->year);
            fprintf(fp, "\"hour\": \"%d:%d\",\n", temporaryEvent->hour, temporaryEvent->minutes);
            fprintf(fp, "\"time\": \"%d\",\n", temporaryEvent->event_time);

            // Remplacer les espaces dans la description par des underscores avant l'écriture
            for (int i = 0; i < strlen(temporaryEvent->eventDescription); ++i) {
                if (temporaryEvent->eventDescription[i] == ' ') {
                    temporaryEvent->eventDescription[i] = '_';
                }
            }

            fprintf(fp, "\"description\": \"%s\"}", temporaryEvent->eventDescription);

            // Rétablir les espaces dans la description après l'écriture
            for (int i = 0; i < strlen(temporaryEvent->eventDescription); ++i) {
                if (temporaryEvent->eventDescription[i] == '_') {
                    temporaryEvent->eventDescription[i] = ' ';
                }
            }

            // Écrire une virgule si ce n'est pas le dernier événement
            if (temporaryEvent->next != NULL) {
                fputs(",\n", fp);
            }

            // Passer à l'événement suivant
            temporaryEvent = temporaryEvent->next;
        }

        // Écrire la fin du tableau JSON pour les événements du contact
        fputs("\n]", fp);

        // Écrire une virgule si ce n'est pas le dernier contact
        if (temporary->arrayOfNexts[0] != NULL) {
            fputs(",\n", fp);
        }

        // Passer au contact suivant
        temporary = temporary->arrayOfNexts[0];
    }

    // Écrire la fin du fichier JSON
    fputs("\n}", fp);

    // Fermer le fichier
    fclose(fp);
}


void loadAgenda(ListOfFloorCells *agenda) {
    FILE *file;

    // Demander le nom du fichier jusqu'à ce qu'il puisse être ouvert avec succès
    do {
        printf("File name: ");
        char *fileName = scanString();
        file = fopen(fileName, "r");
    } while (file == NULL);

    // Déterminer la taille du fichier
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    // Allouer de la mémoire pour contenir le contenu du fichier
    char *jsonContent = (char *) malloc(fileSize + 1);

    // Lire le contenu du fichier dans la mémoire
    fread(jsonContent, 1, fileSize, file);
    jsonContent[fileSize] = '\0';

    // Fermer le fichier
    fclose(file);

    // Utiliser strtok pour analyser le fichier JSON
    char *token = strtok(jsonContent, "{}\":/, \t\n\r");

    // Créer le premier contact avec le nom extrait du fichier
    Contact *currentContact = createContact(token);
    addSortedCellInFloorList(agenda, currentContact);

    // Continuer à analyser le fichier JSON
    while (token != NULL) {
        if (strcmp(token, "]") == 0) {
            // Passer au prochain contact s'il y en a un
            token = strtok(NULL, "{}\":, \t\n\r");
            if (token != NULL) {
                currentContact = createContact(token);
                addSortedCellInFloorList(agenda, currentContact);
            }
            token = strtok(NULL, "{}\":, \t\n\r");
        } else if (strcmp(token, "[") == 0) {
            // Commencer à extraire les événements
            token = strtok(NULL, "{}\":, \t\n\r");
            Event *temporaryEvent;

            // Parcourir les événements dans le tableau JSON
            while (token != NULL && strcmp(token, "Date") == 0) {
                temporaryEvent = createEmptyEvent();

                // Extraire la date de l'événement
                if (strcmp(token, "Date") == 0) {
                    token = strtok(NULL, "{}\"/:, \t\n\r");
                    temporaryEvent->day = convertStringToDigit(token);
                    token = strtok(NULL, "{}\"/:, \t\n\r");
                    temporaryEvent->month = convertStringToDigit(token);
                    token = strtok(NULL, "{}\"/:, \t\n\r");
                    temporaryEvent->year = convertStringToDigit(token);
                }

                // Extraire l'heure de l'événement
                token = strtok(NULL, "{}\"/:, \t\n\r");
                if (strcmp(token, "hour") == 0) {
                    token = strtok(NULL, "{}\":, \t\n\r");
                    temporaryEvent->hour = convertStringToDigit(token);
                    token = strtok(NULL, "{}\":, \t\n\r");
                    temporaryEvent->minutes = convertStringToDigit(token);
                }

                // Extraire la durée de l'événement
                token = strtok(NULL, "{}\":, \t\n\r");
                if (strcmp(token, "time") == 0) {
                    token = strtok(NULL, "{}\":, \t\n\r");
                    temporaryEvent->event_time = convertStringToDigit(token);
                }

                // Extraire la description de l'événement
                token = strtok(NULL, "{}\":, \t\n\r");
                if (strcmp(token, "description") == 0) {
                    token = strtok(NULL, "{}\":, \t\n\r");
                    for (int i = 0; i < strlen(token); ++i) {
                        if (token[i] == '_') {
                            token[i] = ' ';
                        }
                    }
                    temporaryEvent->eventDescription = (char *) malloc(strlen(token) + 1);
                    strcpy(temporaryEvent->eventDescription, token);
                }

                // Passer au prochain événement s'il y en a un
                token = strtok(NULL, "{}\":, \t\n\r");
                addEventInList(&currentContact->listOfEvent, temporaryEvent);
            }
        } else if (token != NULL) {
            // Passer au prochain élément s'il ne s'agit ni d'un contact ni d'un événement
            token = strtok(NULL, "{}\":, \t\n\r");
        }
    }

    // Libérer la mémoire allouée pour le contenu JSON
    free(jsonContent);
}

