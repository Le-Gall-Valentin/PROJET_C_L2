//
// Created by Le Gall on 26/10/2023.
//

#include "ListOfFloorCells.h"


void deleteFloorListRecursivly(FloorCell *list);

ListOfFloorCells *createEmptyFloorList(int nbFloors) {
    ListOfFloorCells *newFloorList = (ListOfFloorCells *) malloc(sizeof(ListOfFloorCells));
    //ArrayOfCell est un tableau des 1er next de la taille nbfloor.
    newFloorList->ArrayOfCell = createArrayOfNexts(nbFloors);
    // on initialise le parametre nbfloor
    newFloorList->nbFloors = nbFloors;
    return newFloorList;
}

void addHeadFloorList(ListOfFloorCells *list, unsigned long long value, int nbFloors) {
    // On initialise une nouvelle floorCell
    FloorCell *newCell = createFloorCell(value, nbFloors);
    for (int i = 0; i < nbFloors; ++i) {
        //initialise tous les pointeur du tableu de nexte de la nouvelle Cell avec les pointeur vers quoi pointer la liste
        newCell->arrayOfNexts[i] = list->ArrayOfCell[i];
    }
    for (int i = 0; i < nbFloors; i++) {
        //set les nbFloor premiers pointeurs du tableau de next de la list pointant sur la nouvelle cell
        list->ArrayOfCell[i] = newCell;
    }
}

void addSortedCellInFloorList(ListOfFloorCells *list, unsigned long long value, int nbFloors) {
    // initialisation d'une nouvelle FloorCell
    FloorCell *newCell = createFloorCell(value, nbFloors);
    //initialise deux FloorCell temporaire
    FloorCell *current = NULL;
    FloorCell *prev = NULL;
    //Parcour de l'étage le plus haut vers le plus bas
    for (int level = nbFloors - 1; level >= 0; --level) {
        //current point sur la valeurs pointée par la liste
        current = list->ArrayOfCell[level];
        prev = NULL;
        //parcours tant que la valeurs de current n'est pas NULL (fin de la liste) ou que current ne rencontre pas de valeurs plus grandes
        while (current != NULL && current->value < value) {
            prev = current;
            current = current->arrayOfNexts[level];
        }
        if (prev == NULL) {
            //Exemple si il n'y a que une valeur sur le level et qu'on ajoute entre cette valeur et la list
            //le prev reste au début de la list
            newCell->arrayOfNexts[level] = list->ArrayOfCell[level];
            list->ArrayOfCell[level] = newCell;
        } else {
            //si on va à gauche car la valeur est plus petite
            //la newcell pointe sur la prochaine cell
            newCell->arrayOfNexts[level] = prev->arrayOfNexts[level];
            //la cell precedente pointe sur la nouvelle
            prev->arrayOfNexts[level] = newCell;
        }
        //on descend d'un level pour faire tous les levls
    }
}


void displayOneFloorOfFloorList(ListOfFloorCells *list, int floor) {
    // Cette fonction permet d'afficher une hauteur spécifié en paramètre 
    if (floor <= list->nbFloors - 1) {
        printf("[list head_%d @-]", floor - 1);
        FloorCell *temporaryCell = list->ArrayOfCell[floor];
        // Parcour jusqu'à se que le temp arrive à NULL
        while (temporaryCell != NULL) {
            printf("-->");
            displayFloorCell(temporaryCell);
            temporaryCell = temporaryCell->arrayOfNexts[floor];
        }
        printf("NULL\n");
    }
}

void displayFloorList(ListOfFloorCells *list) {
    // Cette fonction permet d'afficher toute la liste de façons à se que chaque céllule de chaque hauteur soit alignées
    for (int i = 0; i < list->nbFloors; ++i) {
        printf("[list head_%d @-]", i);
        FloorCell *temporaryCellFloorI = list->ArrayOfCell[i];
        FloorCell *temporaryCellFloor0 = list->ArrayOfCell[0];
        while (temporaryCellFloor0 != NULL) {
            // Si la cellule première cellue de la hauteur i est la même que la cellule de hauteur 0
            if (temporaryCellFloor0 == temporaryCellFloorI) {
                printf("-->");
                // Affichage de la Cell
                displayFloorCell(temporaryCellFloorI);
                //On avance temporaryCellFloorI d'une cellule du même niveau
                temporaryCellFloorI = temporaryCellFloorI->arrayOfNexts[i];
            } else {
                // On printGap ce qui permet de garder les cellules alignées à l'affichage
                printGap(temporaryCellFloor0->value);
            }
            //On avance temporaryCellFloor0 de une cellule sur le niveau 0
            temporaryCellFloor0 = temporaryCellFloor0->arrayOfNexts[0];
        }
        //Afficher le dernier pointeur de la liste qui est null
        printf("-> NULL\n");
    }
}

ListOfFloorCells *createSortedListWithNValues(int n) {
    ListOfFloorCells *sortedList = createEmptyFloorList(n);
    for (int i = (int) pow(2, n) - 1; i > 0; --i) {
        // Ajoute en tête de sortedList une FloorCell de valeur i et de nbFloor nbDivideBy2(i) +1 
        addHeadFloorList(sortedList, i, (int) nbDivideBy2(i) + 1);
    }
    return sortedList;
}

int classicSearchValueInFloorList(ListOfFloorCells *list, unsigned long long value) {
    FloorCell *temporaryCell = list->ArrayOfCell[0];
    // Tant qu'on arrive pas à la fin de la liste ou que nous n'avons pas trouvé la valeur cherché
    while (temporaryCell->arrayOfNexts[0] != NULL && temporaryCell->value != value) {
        temporaryCell = temporaryCell->arrayOfNexts[0];
    }
    // Si on trouve la valeur alors on retourne 1 pour dire qu'elle y est
    if (temporaryCell->value == value) {
        return 1;
    }
    return 0;
}

int levelSearchValueInFloorList(ListOfFloorCells *list, unsigned long long value) {
    FloorCell *temporary = list->ArrayOfCell[list->nbFloors - 1];
    FloorCell *previous = NULL;
    // parcours de la dernière hauteur à la plus basse
    for (int i = list->nbFloors - 1; i >= 0; --i) {
        if (temporary->value == value) {
            return 1;
        //Si ma valeur cherché est plus grande alorsje vais à droite 
        } else if (value > temporary->value) {
            previous = temporary;
            temporary = temporary->arrayOfNexts[i - 1];
        } else {
            if (previous == NULL) {
                temporary = list->ArrayOfCell[i - 1];
            } else {
                temporary = previous->arrayOfNexts[i - 1];
            }
        }
    }
    return 0;
}

void deleteFloorList(ListOfFloorCells *list) {
    FloorCell *previous = NULL;
    FloorCell *temporary = list->ArrayOfCell[0];
    //Supprimer chaque Cell de la liste
    while (temporary != NULL) {
        previous = temporary;
        temporary = temporary->arrayOfNexts[0];
        deleteFloorCell(previous);
    }
    free(list->ArrayOfCell);
    free(list);
}
