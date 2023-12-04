//
// Created by Le Gall on 26/10/2023.
//

#include "ListOfFloorCells.h"


ListOfFloorCells *createEmptyFloorList(int nbFloors) {
    ListOfFloorCells *newFloorList = (ListOfFloorCells *) malloc(sizeof(ListOfFloorCells));
    //ArrayOfCell est un tableau des 1er next de la taille nbfloor.
    newFloorList->ArrayOfCell = createArrayOfNexts(nbFloors);
    // on initialise le parametre nbfloor
    newFloorList->nbFloors = nbFloors;
    return newFloorList;
}

void addHeadFloorList(ListOfFloorCells *list, Contact *contact, int nbFloors) {

    FloorCell *newCell = createFloorCell(contact, nbFloors);
    for (int i = 0; i < nbFloors; ++i) {
        //initialise tous les pointeur du tableu de nexte de la nouvelle Cell avec les pointeur vers quoi pointer la liste
        newCell->arrayOfNexts[i] = list->ArrayOfCell[i];
    }
    for (int i = 0; i < nbFloors; i++) {
        //set les nbFloor premiers pointeurs du tableau de next de la list pointant sur la nouvelle cell
        list->ArrayOfCell[i] = newCell;
    }
}

int strcompByLevels(const char *str1, const char *str2, int index) {
    // compare deux caractères et renvoie un entier correspondant à chaque cas
    for (int i = 0; i <= index; ++i) {
        if (str1[i] > str2[i]) {
            return 1;
        } else if (str1[i] < str2[i]) {
            return -1;
        }
    }
    return 0;
}


void addSortedCellInFloorList(ListOfFloorCells *list, Contact *contact) {
    // Fonction pour ajouter un contact trié dans la liste à étages
    FloorCell *newCell = createFloorCell(contact, 4);
    // level maximal imposé par le TP
    int level = 3;
    FloorCell *current = NULL;
    FloorCell *prev = NULL;
    while (level >= 0) {
        // on se met sur le niveau level et current prend la première cellules de ce niveau
        current = list->ArrayOfCell[level];
        prev = NULL;
        // tant que le nom du contact est plus grand que celui du curent
        while (current != NULL && strcmp(current->value->lastnameFirstname, contact->lastnameFirstname) < 0) {
            // on avance current vers la droite sur le meme niveau et previous prend la valeurs précédente
            prev = current;
            current = current->arrayOfNexts[level];
        }
        if (prev == NULL) {
            //si le prev est nulle alors c'est que ma nouvelle cellule est la première du niveau
            newCell->arrayOfNexts[level] = list->ArrayOfCell[level];
            list->ArrayOfCell[level] = newCell;
        } else {
            // si les 4 premières lettres sont équivalentes alors on modifie la taille de nbFloor à 1 et on ajoute après prev
            if (level == newCell->nbFloors - 1 &&
                strcompByLevels(prev->value->lastnameFirstname, newCell->value->lastnameFirstname, 3) == 0) {
                newCell->nbFloors = 1;
                newCell->arrayOfNexts = (FloorCell **) realloc(newCell->arrayOfNexts,
                                                               newCell->nbFloors * sizeof(FloorCell *));
                newCell->arrayOfNexts[0] = prev->arrayOfNexts[0];
                prev->arrayOfNexts[0] = newCell;
                level = -1;
            } else if (strcompByLevels(prev->value->lastnameFirstname, newCell->value->lastnameFirstname, 3 - level) !=
                       0) {
                newCell->arrayOfNexts[level] = prev->arrayOfNexts[level];
                prev->arrayOfNexts[level] = newCell;
            } else {
                newCell->nbFloors--;
                newCell->arrayOfNexts = (FloorCell **) realloc(newCell->arrayOfNexts,
                                                               newCell->nbFloors * sizeof(FloorCell *));
            }
        }
        if (level >= 0 && newCell->nbFloors - 1 >= level && newCell->arrayOfNexts[level] != NULL &&
            strcompByLevels(newCell->value->lastnameFirstname,
                            newCell->arrayOfNexts[level]->value->lastnameFirstname,
                            3 - level) == 0) {
            FloorCell *temp = newCell->arrayOfNexts[level];
            newCell->arrayOfNexts[level] = newCell->arrayOfNexts[level]->arrayOfNexts[level];
            temp->nbFloors--;
            temp->arrayOfNexts = (FloorCell **) realloc(temp->arrayOfNexts, temp->nbFloors * sizeof(FloorCell *));
        }
        level--;
    }
}

void displayFloorList(ListOfFloorCells *list) {
    //Affiche la liste à niveau en ne montrant que les noms
    for (int i = 0; i < list->nbFloors; ++i) {
        printf("[list head_%d @-]", i);
        FloorCell *temporaryCellFloorI = list->ArrayOfCell[i];
        FloorCell *temporaryCellFloor0 = list->ArrayOfCell[0];
        while (temporaryCellFloor0 != NULL) {
            if (temporaryCellFloor0 == temporaryCellFloorI) {
                printf("-->");
                displayFloorCellName(temporaryCellFloorI);
                temporaryCellFloorI = temporaryCellFloorI->arrayOfNexts[i];
            } else {
                printGapChar(temporaryCellFloor0->value->lastnameFirstname);
            }
            temporaryCellFloor0 = temporaryCellFloor0->arrayOfNexts[0];
        }
        printf("-> NULL\n");
    }
}

FloorCell *classicSearchValueInFloorList(ListOfFloorCells *list, char *name) {
    //
    FloorCell *temporaryCell = list->ArrayOfCell[0];
    if (temporaryCell == NULL) {
        return NULL;
    }
    while (temporaryCell->arrayOfNexts[0] != NULL && strcmp(temporaryCell->value->lastnameFirstname, name) != 0) {
        temporaryCell = temporaryCell->arrayOfNexts[0];
    }
    if (strcmp(temporaryCell->value->lastnameFirstname, name) == 0) {
        return temporaryCell;
    }
    return NULL;
}

FloorCell *levelSearchValueInFloorList(ListOfFloorCells *list, char *name) {
    if (list == NULL || list->ArrayOfCell == NULL) {
        return NULL;  // La liste est vide
    }

    FloorCell *temporary = list->ArrayOfCell[list->nbFloors - 1];
    FloorCell *previous = NULL;

    for (int i = list->nbFloors - 1; i >= 0; --i) {
        while (temporary != NULL) {
            if (strcmp(temporary->value->lastnameFirstname, name) == 0) {
                return temporary;  // Le contact a été trouvé
            } else if (strcmp(name, temporary->value->lastnameFirstname) > 0) {
                previous = temporary;
                temporary = temporary->arrayOfNexts[i];
            } else {
                break;  // Arrête la recherche sur ce niveau
            }
        }

        // Ajuste le point de départ pour le niveau inférieur
        if (previous == NULL) {
            temporary = list->ArrayOfCell[i - 1];
        } else {
            temporary = previous->arrayOfNexts[i - 1];
        }
    }

    return NULL;  // Le contact n'a pas été trouvé
}

void deleteFloorList(ListOfFloorCells *list) {
    FloorCell *previous = NULL;
    FloorCell *temporary = list->ArrayOfCell[0];
    while (temporary != NULL) {
        previous = temporary;
        temporary = temporary->arrayOfNexts[0];
        deleteFloorCell(previous);
    }
    free(list->ArrayOfCell);
    free(list);
}

void displayAllValues(ListOfFloorCells *list) {
    FloorCell *temporary = list->ArrayOfCell[0];
    while (temporary != NULL) {
        printf("%s ", temporary->value->lastnameFirstname);
        temporary = temporary->arrayOfNexts[0];
    }
}
