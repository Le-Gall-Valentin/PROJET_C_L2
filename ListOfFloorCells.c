//
// Created by Le Gall on 26/10/2023.
//

#include "ListOfFloorCells.h"


ListOfFloorCells *createEmptyFloorList(int nbFloors) {
    ListOfFloorCells *newFloorList = (ListOfFloorCells *) malloc(sizeof(ListOfFloorCells));
    //ArrayOfCell est un tableau des 1er next de la taille nbfloor.
    newFloorList->ArrayOfCell = createArrayOfNexts(nbFloors);
    // on set le parametre nbfloor
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

//void addSortedCellInFloorList(ListOfFloorCells *list, Contact *contact, int nbFloors) {
//    FloorCell *newCell = createFloorCell(contact, nbFloors);
//    if (list == NULL) {
//        for (int i = 0; i < nbFloors; ++i) {
//            // Si la list est vide ajouter direct
//            list->ArrayOfCell[i] = newCell;
//        }
//        return;
//    }
//    FloorCell *current = NULL;
//    FloorCell *prev = NULL;
//    int level = nbFloors - 1;
//    while (level >= 0) {
//        current = list->ArrayOfCell[level];
//        prev = NULL;
//        while (current != NULL && current->value->lastnameFirstname < contact->lastnameFirstname) {
//            prev = current;
//            current = current->arrayOfNexts[level];
//        }
//        if (prev == NULL) {
//            //Exemple si il n'y a que une valeur sur le level et qu'on ajoute entre cette valeur et la list
//            //le prev reste au début de la list
//            newCell->arrayOfNexts[level] = list->ArrayOfCell[level];
//            list->ArrayOfCell[level] = newCell;
//        } else {
//            //si on va à gauche car la valeur est plus petite
//            //la new cell pointe sur la prochaine cell
//            newCell->arrayOfNexts[level] = prev->arrayOfNexts[level];
//            //la cell precedente pointe sur la nouvelle
//            prev->arrayOfNexts[level] = newCell;
//        }
//        //on descend d'un level pour faire tous les levls
//        level--;
//    }
//}

//void addSortedCellInFloorList2(ListOfFloorCells *list, Contact *contact) {
//    if (list->ArrayOfCell[3] == NULL) {
//        addHeadFloorList(list, contact, 4);
//    } else {
//        FloorCell *temporary = list->ArrayOfCell[0];
//        FloorCell *previous;
//        int higher;
//        while (temporary != NULL || temporary->value->lastnameFirstname[0] != contact->lastnameFirstname[0]) {
//            previous = temporary;
//            temporary = temporary->arrayOfNexts[0];
//        }
//    }
//}



int testplusgrand(Contact *temp, Contact *temp_next) {
    int i = 0;
    while (i < 4) {
        if (temp->lastnameFirstname[i] == temp_next->lastnameFirstname[i]) {
            i += 1;
        } else {
            if (temp->lastnameFirstname[i] > temp_next->lastnameFirstname[i]) {
                return 0;
            } else {
                return 1;
            }
        }
    }
}

void addSortedCellInFloorList3(ListOfFloorCells *list, Contact *contact) {
    if (list->ArrayOfCell[3] == NULL) {
        addHeadFloorList(list, contact, 4);
    } else {
        FloorCell *temporary = list->ArrayOfCell[0];
        FloorCell *previous;
        int higher = 1;
        while (temporary != NULL || higher == 0) {
            higher = testplusgrand(temporary, temporary->arrayOfNexts[0]);
            previous = temporary;
            temporary = temporary->arrayOfNexts[0];
        }
    }
}



void displayOneFloorOfFloorList(ListOfFloorCells *list, int floor) {
    if (floor <= list->nbFloors - 1) {
        printf("[list head_%d @-]", floor - 1);
        FloorCell *temporaryCell = list->ArrayOfCell[floor];
        while (temporaryCell != NULL) {
            printf("-->");
            displayFloorCellName(temporaryCell);
            temporaryCell = temporaryCell->arrayOfNexts[floor];
        }
        printf("NULL\n");
    }
}

void displayFloorList(ListOfFloorCells *list) {
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

//ListOfFloorCells *createSortedListWithNValues(int n) {
//    ListOfFloorCells *sortedList = createEmptyFloorList(n);
//    for (int i = (int) pow(2, n) - 1; i > 0; --i) {
//        //ajout une cell en tete de liste de valeur i et de nbfloor égale à celui trouvé dans le tableau
//        addHeadFloorList(sortedList, i, (int) nbDivideBy2(i) + 1);
//    }
//    return sortedList;
//}

//int classicSearchValueInFloorList(ListOfFloorCells *list, unsigned long long value) {
//    FloorCell *temporaryCell = list->ArrayOfCell[0];
//    while (temporaryCell->arrayOfNexts[0] != NULL && temporaryCell->value != value) {
//        temporaryCell = temporaryCell->arrayOfNexts[0];
//    }
//    if (temporaryCell->value == value) {
//        return 1;
//    }
//    return 0;
//}

//int levelSearchValueInFloorList(ListOfFloorCells *list, unsigned long long value) {
//    FloorCell *temporary = list->ArrayOfCell[list->nbFloors - 1];
//    FloorCell *previous = NULL;
//    for (int i = list->nbFloors - 1; i >= 0; --i) {
//        if (temporary->value == value) {
//            return 1;
//        } else if (value > temporary->value) {
//            previous = temporary;
//            temporary = temporary->arrayOfNexts[i - 1];
//        } else {
//            if (previous == NULL) {
//                temporary = list->ArrayOfCell[i - 1];
//            } else {
//                temporary = previous->arrayOfNexts[i - 1];
//            }
//        }
//    }
//    return 0;
//}

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