//
// Created by Le Gall on 03/12/2023.
//

#include "manageJson.h"

void saveAgenda(ListOfFloorCells *agenda) {
    FILE *fp;
    do {
        printf("file name : ");
        char *fileName = scanString();
        fp = fopen(fileName, "w");
    } while (fp == NULL);
    fputs("{\n", fp);
    FloorCell *temporary = agenda->ArrayOfCell[0];
    while (temporary != NULL) {
        fprintf(fp, "\"%s\": [\n", temporary->value->lastnameFirstname);
        Event *temporaryEvent = temporary->value->listOfEvent;
        while (temporaryEvent != NULL) {
            fprintf(fp, "{\"Date\": \"%d/%d/%d\",\n", temporaryEvent->day, temporaryEvent->month, temporaryEvent->year);
            fprintf(fp, "\"hour\": \"%d:%d\",\n", temporaryEvent->hour, temporaryEvent->minutes);
            fprintf(fp, "\"time\": \"%d\",\n", temporaryEvent->event_time);
            for (int i = 0; i < strlen(temporaryEvent->eventDescription); ++i) {
                if (temporaryEvent->eventDescription[i] == ' ') {
                    temporaryEvent->eventDescription[i] = '_';
                }
            }
            fprintf(fp, "\"description\": \"%s\"}", temporaryEvent->eventDescription);
            for (int i = 0; i < strlen(temporaryEvent->eventDescription); ++i) {
                if (temporaryEvent->eventDescription[i] == '_') {
                    temporaryEvent->eventDescription[i] = ' ';
                }
            }
            if (temporaryEvent->next != NULL) {
                fputs(",\n", fp);
            }
            temporaryEvent = temporaryEvent->next;
        }
        fputs("\n]", fp);
        if (temporary->arrayOfNexts[0] != NULL) {
            fputs(",\n", fp);
        }
        temporary = temporary->arrayOfNexts[0];
    }
    fputs("\n}", fp);
    fclose(fp);
}


void loadAgenda(ListOfFloorCells *agenda) {
    FILE *file;
    do {
        printf("file name : ");
        char *fileName = scanString();
        file = fopen(fileName, "r");
    } while (file == NULL);

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    char *jsonContent = (char *) malloc(fileSize + 1);
    fread(jsonContent, 1, fileSize, file);
    jsonContent[fileSize] = '\0';
    fclose(file);


    char *token = strtok(jsonContent, "{}\":/, \t\n\r");
    Contact *currentContact = createContact(token);
    addSortedCellInFloorList(agenda, currentContact);
    while (token != NULL) {
        if (strcmp(token, "]") == 0) {
            token = strtok(NULL, "{}\":, \t\n\r");
            if (token != NULL) {
                currentContact = createContact(token);
                addSortedCellInFloorList(agenda, currentContact);
            }
            token = strtok(NULL, "{}\":, \t\n\r");
        } else if (strcmp(token, "[") == 0) {
            token = strtok(NULL, "{}\":, \t\n\r");
            Event *temporaryEvent;
            while (token != NULL && strcmp(token, "Date") == 0) {
                temporaryEvent = createEmptyEvent();
                if (strcmp(token, "Date") == 0) {
                    token = strtok(NULL, "{}\"/:, \t\n\r");
                    temporaryEvent->day = convertStringToDigit(token);
                    token = strtok(NULL, "{}\"/:, \t\n\r");
                    temporaryEvent->month = convertStringToDigit(token);
                    token = strtok(NULL, "{}\"/:, \t\n\r");
                    temporaryEvent->year = convertStringToDigit(token);
                }
                token = strtok(NULL, "{}\"/:, \t\n\r");
                if (strcmp(token, "hour") == 0) {
                    token = strtok(NULL, "{}\":, \t\n\r");
                    temporaryEvent->hour = convertStringToDigit(token);
                    token = strtok(NULL, "{}\":, \t\n\r");
                    temporaryEvent->minutes = convertStringToDigit(token);
                }
                token = strtok(NULL, "{}\":, \t\n\r");
                if (strcmp(token, "time") == 0) {
                    token = strtok(NULL, "{}\":, \t\n\r");
                    temporaryEvent->event_time = convertStringToDigit(token);
                }
                token = strtok(NULL, "{}\":, \t\n\r");
                if (strcmp(token, "description") == 0) {
                    token = strtok(NULL, "{}\":, \t\n\r");
                    for (int i = 0; i < strlen(token); ++i) {
                        if (token[i] == '_') {
                            token[i] = ' ';
                        }
                    }
                    temporaryEvent->eventDescription = (char *) malloc(strlen(token) * sizeof(char));
                    strcpy(temporaryEvent->eventDescription, token);
                }
                token = strtok(NULL, "{}\":, \t\n\r");
                addEventInList(&currentContact->listOfEvent, temporaryEvent);
            }
        } else if (token != NULL) {
            token = strtok(NULL, "{}\":, \t\n\r");
        }
    }
}
