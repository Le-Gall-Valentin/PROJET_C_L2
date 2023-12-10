//
// Created by Le Gall on 26/10/2023.
//

#include "ListOfFloorCells.h"


ListOfFloorCells *createEmptyFloorList(int nbFloors) {
    // Alloue de la mémoire pour la nouvelle liste de cellules de planchers
    ListOfFloorCells *newFloorList = (ListOfFloorCells *) malloc(sizeof(ListOfFloorCells));

    // Initialise le tableau de pointeurs vers des cellules de planchers avec des cellules nulles
    newFloorList->ArrayOfCell = createArrayOfNexts(nbFloors);

    // Initialise le nombre d'étages dans la liste
    newFloorList->nbFloors = nbFloors;

    // Retourne la nouvelle liste créée
    return newFloorList;
}


void addHeadFloorList(ListOfFloorCells *list, Contact *contact, int nbFloors) {
    // Crée une nouvelle cellule avec le contact spécifié et le nombre d'étages
    FloorCell *newCell = createFloorCell(contact, nbFloors);

    // Initialise tous les pointeurs du tableau de next de la nouvelle cellule avec les pointeurs vers les cellules actuelles de la liste
    for (int i = 0; i < nbFloors; ++i) {
        newCell->arrayOfNexts[i] = list->ArrayOfCell[i];
    }

    // Set les nbFloors premiers pointeurs du tableau de next de la liste pointant sur la nouvelle cellule
    for (int i = 0; i < nbFloors; i++) {
        list->ArrayOfCell[i] = newCell;
    }
}

void addSortedCellInFloorList(ListOfFloorCells *list, Contact *contact) {
    // Crée une nouvelle cellule avec le contact spécifié et 4 étages (niveau 0 à niveau 3)
    FloorCell *newCell = createFloorCell(contact, 4);
    FloorCell *current = NULL;
    FloorCell *prev = NULL;
    for (int level = 3; level >= 0; --level) {
        // Récupère la cellule actuelle au niveau spécifié
        current = list->ArrayOfCell[level];
        prev = NULL;

        // Parcourt la liste jusqu'à trouver la position appropriée pour la nouvelle cellule
        while (current != NULL && strcmp(current->value->lastnameFirstname, contact->lastnameFirstname) < 0) {
            // on avance current vers la droite sur le meme niveau et previous prend la valeurs précédente
            prev = current;
            current = current->arrayOfNexts[level];
        }

        // Insertion de la nouvelle cellule à la position trouvée
        if (prev == NULL) {
            //si le prev est nulle alors c'est que ma nouvelle cellule est la première du niveau
            newCell->arrayOfNexts[level] = list->ArrayOfCell[level];
            list->ArrayOfCell[level] = newCell;
        } else {
            // si les 4 premières lettres sont équivalentes alors on modifie la taille de nbFloor à 1 et on ajoute après prev
            if (level == newCell->nbFloors - 1 &&
                strcompByLevels(prev->value->lastnameFirstname, newCell->value->lastnameFirstname, 3) == 0) {
                // Cas spécial : fusionne les cellules si le prédecesseur et le nouveau contact ont le même préfixe jusqu'au niveau 3
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
                // Redimensionne le tableau de nexts si nécessaire pour éviter des niveaux redondants
                newCell->nbFloors--;
                newCell->arrayOfNexts = (FloorCell **) realloc(newCell->arrayOfNexts,
                                                               newCell->nbFloors * sizeof(FloorCell *));
            }
        }

        // Supprime les niveaux redondants
        if (level >= 0 && newCell->nbFloors - 1 >= level && newCell->arrayOfNexts[level] != NULL &&
            strcompByLevels(newCell->value->lastnameFirstname, newCell->arrayOfNexts[level]->value->lastnameFirstname,
                            3 - level) == 0) {
            FloorCell *temp = newCell->arrayOfNexts[level];
            newCell->arrayOfNexts[level] = newCell->arrayOfNexts[level]->arrayOfNexts[level];
            temp->nbFloors--;
            temp->arrayOfNexts = (FloorCell **) realloc(temp->arrayOfNexts, temp->nbFloors * sizeof(FloorCell *));
        }
    }
}


void displayFloorList(ListOfFloorCells *list) {
    //Affiche la liste à niveau en ne montrant que les noms
    for (int i = 0; i < list->nbFloors; ++i) {
        printf("[list head_%d @-]", i);
        FloorCell *temporaryCellFloorI = list->ArrayOfCell[i];
        FloorCell *temporaryCellFloor0 = list->ArrayOfCell[0];

        // Parcourt la liste en affichant les informations pour chaque cellule
        while (temporaryCellFloor0 != NULL) {
            if (temporaryCellFloor0 == temporaryCellFloorI) {
                printf("-->");
                // Affiche le nom du contact dans la cellule
                displayFloorCellName(temporaryCellFloorI);
                temporaryCellFloorI = temporaryCellFloorI->arrayOfNexts[i];
            } else {
                // Affiche un espace correspondant à la largeur du nom du contact pour maintenir l'alignement
                printGapChar(temporaryCellFloor0->value->lastnameFirstname);
            }
            temporaryCellFloor0 = temporaryCellFloor0->arrayOfNexts[0];
        }

        // Affiche la fin de la liste
        printf("-> NULL\n");
    }
}


FloorCell *classicSearchValueInFloorList(ListOfFloorCells *list, char *name) {
    //Cherche une valeur de manièere classic c'est à dire en parcourant la couche 0
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
    // Vérifie si la liste ou la liste d'étages est vide
    if (list == NULL || list->ArrayOfCell == NULL) {
        return NULL;
    }

    FloorCell *temporary = list->ArrayOfCell[list->nbFloors - 1];
    FloorCell *previous = NULL;

    // Parcourt la liste d'étages de haut en bas
    for (int i = list->nbFloors - 1; i >= 0; --i) {
        while (temporary != NULL) {
            // Vérifie si le nom a été trouvé
            if (strcmp(temporary->value->lastnameFirstname, name) == 0) {
                return temporary;
            } else if (strcmp(name, temporary->value->lastnameFirstname) > 0) {
                // Continue la recherche au niveau inférieur
                previous = temporary;
                temporary = temporary->arrayOfNexts[i];
            } else {
                // Si le nom est inférieur, passe au niveau inférieur
                temporary = NULL;
            }
        }

        // Si le niveau inférieur est atteint, ajuste le pointeur temporaire
        if (previous == NULL) {
            temporary = list->ArrayOfCell[i - 1];
        } else {
            // On reprend la recherche sur le niveau suivant depuis la valeur prev
            temporary = previous->arrayOfNexts[i - 1];
        }
    }

    // Retourne NULL si le nom n'est pas trouvé dans la liste
    return NULL;
}


void deleteFloorList(ListOfFloorCells *list) {
    // supprime une FloorList de contat
    FloorCell *previous = NULL;
    FloorCell *temporary = list->ArrayOfCell[0];

    // Parcourt la liste d'étages
    while (temporary != NULL) {
        previous = temporary;
        temporary = temporary->arrayOfNexts[0];

        // Supprime la cellule d'étage
        deleteFloorCell(previous);
    }

    // Libère la mémoire allouée pour le tableau de pointeurs vers les cellules d'étage
    free(list->ArrayOfCell);

    // Libère la mémoire allouée pour la structure de liste d'étages
    free(list);
}

void displayAllValues(ListOfFloorCells *list) {
    //affiche toutes les valeurs de la list de contact
    FloorCell *temporary = list->ArrayOfCell[0];

    // Parcourt la liste d'étages
    while (temporary != NULL) {
        // Affiche le nom stocké dans la cellule d'étage actuelle
        printf("%s ", temporary->value->lastnameFirstname);

        // Passe à la cellule d'étage suivante sur le niveau 0
        temporary = temporary->arrayOfNexts[0];
    }
    printf("\n");
}
