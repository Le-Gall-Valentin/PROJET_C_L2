//
// Created by Le Gall on 26/10/2023.
//

#include "ListOfFloorCells.h"


ListOfFloorCells *createEmptyFloorList(int nbFloors) {
    // Alloue dynamiquement de la mémoire pour une nouvelle instance de ListOfFloorCells
    ListOfFloorCells *newFloorList = (ListOfFloorCells *) malloc(sizeof(ListOfFloorCells));

    // Initialise le tableau de pointeurs vers des cellules d'étages suivants
    newFloorList->ArrayOfCell = createArrayOfNexts(nbFloors);

    // Initialise le nombre d'étages dans la liste
    newFloorList->nbFloors = nbFloors;

    // Retourne la nouvelle instance de ListOfFloorCells
    return newFloorList;
}


void addHeadFloorList(ListOfFloorCells *list, unsigned long long value, int nbFloors) {
    // Crée une nouvelle cellule avec la valeur et le nombre d'étages spécifiés
    FloorCell *newCell = createFloorCell(value, nbFloors);

    // Met à jour les pointeurs de la nouvelle cellule pour pointera vers les étages suivants de la liste
    for (int i = 0; i < nbFloors; ++i) {
        newCell->arrayOfNexts[i] = list->ArrayOfCell[i];
    }

    // Met à jour les pointeurs de la liste pour pointera vers la nouvelle cellule
    for (int i = 0; i < nbFloors; i++) {
        list->ArrayOfCell[i] = newCell;
    }
}

void addSortedCellInFloorList(ListOfFloorCells *list, unsigned long long value, int nbFloors) {
    // Crée une nouvelle cellule avec la valeur et le nombre d'étages spécifiés
    FloorCell *newCell = createFloorCell(value, nbFloors);

    // Déclarations de pointeurs pour la navigation dans la liste
    FloorCell *current = NULL;
    FloorCell *prev = NULL;

    // Parcourt chaque niveau (étage) de la liste
    for (int level = nbFloors - 1; level >= 0; --level) {
        // Initialise les pointeurs pour la traversée
        current = list->ArrayOfCell[level];
        prev = NULL;

        // Parcourt la liste jusqu'à trouver la bonne position pour la nouvelle cellule
        while (current != NULL && current->value < value) {
            prev = current;
            current = current->arrayOfNexts[level];
        }

        // Insère la nouvelle cellule à la bonne position
        if (prev == NULL) {
            newCell->arrayOfNexts[level] = list->ArrayOfCell[level];
            list->ArrayOfCell[level] = newCell;
        } else {
            newCell->arrayOfNexts[level] = prev->arrayOfNexts[level];
            prev->arrayOfNexts[level] = newCell;
        }
    }
}


void displayOneFloorOfFloorList(ListOfFloorCells *list, int floor) {
    // Vérifie que l'étage spécifié est valide
    if (floor <= list->nbFloors - 1) {
        // Affiche le début de la liste pour cet étage
        printf("[list head_%d @-]", floor);

        // Initialise un pointeur temporaire pour la navigation dans la liste
        FloorCell *temporaryCell = list->ArrayOfCell[floor];

        // Parcourt la liste et affiche chaque cellule pour cet étage
        while (temporaryCell != NULL) {
            printf("-->");
            displayFloorCell(temporaryCell);
            temporaryCell = temporaryCell->arrayOfNexts[floor];
        }

        // Affiche NULL à la fin de la liste
        printf("NULL\n");
    }
}

void displayFloorList(ListOfFloorCells *list) {
    // Parcourt chaque étage de la liste
    for (int i = 0; i < list->nbFloors; ++i) {
        // Affiche le début de la liste pour cet étage
        printf("[list head_%d @-]", i);

        // Initialise les pointeurs temporaires pour la navigation dans les étages
        FloorCell *temporaryCellFloorI = list->ArrayOfCell[i];
        FloorCell *temporaryCellFloor0 = list->ArrayOfCell[0];

        // Parcourt la liste pour l'étage 0
        while (temporaryCellFloor0 != NULL) {
            // Vérifie si la cellule actuelle de l'étage 0 correspond à celle de l'étage courant
            if (temporaryCellFloor0 == temporaryCellFloorI) {
                printf("-->");
                displayFloorCell(temporaryCellFloorI);
                temporaryCellFloorI = temporaryCellFloorI->arrayOfNexts[i];
            } else {
                // Affiche un espace correspondant à la valeur de la cellule de l'étage 0
                printGap(temporaryCellFloor0->value);
            }
            temporaryCellFloor0 = temporaryCellFloor0->arrayOfNexts[0];
        }

        // Affiche "NULL" à la fin de la liste pour cet étage
        printf("-> NULL\n");
    }
}

ListOfFloorCells *createSortedListWithNValues(int n) {
    // Crée une nouvelle liste vide avec n étages
    ListOfFloorCells *sortedList = createEmptyFloorList(n);

    // Remplit la liste avec des valeurs triées
    for (int i = (int) pow(2, n) - 1; i > 0; --i) {
        // Ajoute la valeur i à la tête de la liste avec le nombre d'étages déterminé par nbDivideBy2(i) + 1
        addHeadFloorList(sortedList, i, (int) nbDivideBy2(i) + 1);
    }

    // Retourne la liste triée
    return sortedList;
}

int classicSearchValueInFloorList(ListOfFloorCells *list, unsigned long long value) {
    // Initialise un pointeur temporaire pour la navigation dans la liste au niveau 0
    FloorCell *temporaryCell = list->ArrayOfCell[0];

    // Tant qu'on n'arrive pas à la fin de la liste ou qu'on n'a pas trouvé la valeur cherchée
    while (temporaryCell->arrayOfNexts[0] != NULL && temporaryCell->value != value) {
        temporaryCell = temporaryCell->arrayOfNexts[0];
    }

    // Si on trouve la valeur, on retourne 1 pour indiquer qu'elle est présente, sinon on retourne 0
    if (temporaryCell->value == value) {
        return 1;
    }

    return 0;
}

int levelSearchValueInFloorList(ListOfFloorCells *list, unsigned long long value) {
    // Initialise les pointeurs temporaires pour la navigation dans la liste
    FloorCell *temporary = list->ArrayOfCell[list->nbFloors - 1];
    FloorCell *previous = NULL;

    // Parcourt les niveaux de la liste en commençant par le niveau le plus élevé
    for (int i = list->nbFloors - 1; i >= 0; --i) {
        // Vérifie si la valeur est égale à la valeur de la cellule actuelle au niveau i
        if (temporary->value == value) {
            return 1;  // La valeur est trouvée, retourne 1
        } else if (value > temporary->value) {
            // Si la valeur est supérieure à la valeur de la cellule actuelle, déplace les pointeurs vers la cellule suivante au niveau inférieur
            previous = temporary;
            temporary = temporary->arrayOfNexts[i - 1];
        } else {
            // Si la valeur est inférieure à la valeur de la cellule actuelle,
            // déplace les pointeurs vers la cellule au même niveau ou vers la cellule précédente au niveau inférieur
            if (previous == NULL) {
                temporary = list->ArrayOfCell[i - 1];
            } else {
                temporary = previous->arrayOfNexts[i - 1];
            }
        }
    }

    // Si la boucle se termine sans trouver la valeur, retourne 0
    return 0;
}


void deleteFloorList(ListOfFloorCells *list) {
    // Déclarations des pointeurs temporaires
    FloorCell *previous = NULL;
    FloorCell *temporary = list->ArrayOfCell[0];

    // Parcourt la liste et libère la mémoire pour chaque cellule
    while (temporary != NULL) {
        previous = temporary;
        temporary = temporary->arrayOfNexts[0];
        deleteFloorCell(previous);
    }

    // Libère la mémoire allouée pour le tableau de pointeurs
    free(list->ArrayOfCell);

    // Libère la mémoire allouée pour la structure ListOfFloorCells elle-même
    free(list);
}