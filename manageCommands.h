//
// Created by Le Gall on 29/11/2023.
//

#ifndef PROJET_C_L2_5_MANAGECOMMANDS_H
#define PROJET_C_L2_5_MANAGECOMMANDS_H

#include "string.h"
#include "stdio.h"
#include "ListOfFloorCells.h"

void makeCommand(char *command, int *state, ListOfFloorCells *agenda);

void viewContact(ListOfFloorCells *agenda);

void help();

void addNewMeet(ListOfFloorCells *agenda);

void deleteMeet(ListOfFloorCells *agenda);

#endif //PROJET_C_L2_5_MANAGECOMMANDS_H
