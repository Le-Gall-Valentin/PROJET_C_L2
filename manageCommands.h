//
// Created by Le Gall on 29/11/2023.
//

#ifndef PROJET_C_L2_5_MANAGECOMMANDS_H
#define PROJET_C_L2_5_MANAGECOMMANDS_H

#include "string.h"
#include "stdio.h"
#include "ListOfFloorCells.h"
#include "manageJson.h"

void makeCommand(char *command, unsigned short *state, unsigned short *autoComplete, ListOfFloorCells *agenda);

void viewContact(ListOfFloorCells *agenda, unsigned short autoComplete);

void help();

void addNewMeet(ListOfFloorCells *agenda, unsigned short autoComplete);

void deleteMeet(ListOfFloorCells *agenda, unsigned short autoComplete);

void changeAutoComplete(unsigned short *autoComplete);

FloorCell *searchInAgendaWithAutoCompletion(ListOfFloorCells *agenda, unsigned short autoComplete, char **name);

#endif //PROJET_C_L2_5_MANAGECOMMANDS_H
