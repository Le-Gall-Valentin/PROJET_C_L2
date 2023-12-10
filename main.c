#include <stdio.h>
#include "ListOfFloorCells.h"
#include "timer.h"
#include "string.h"

int main() {
    // Initialise la graine pour la fonction rand() avec le temps actuel
    srand(time(NULL));

    // Boucle principale, effectue des tests pour différentes tailles de listes
    for (int i = 1; i <= 25; ++i) {
        // Redirige la sortie standard vers un fichier "classicSearch.txt"
        FILE *f = freopen("classicSearch.txt", "a", stdout);

        // Crée une liste triée avec N valeurs
        ListOfFloorCells *myList = createSortedListWithNValues(i);

        // Affiche la taille de la liste
        printf("%d; ", i);

        // Mesure le temps pour effectuer 10 000 recherches classiques dans la liste
        startTimer();
        for (int j = 0; j < 10000; ++j) {
            unsigned long long searchValue = (getLongRandomNumber() % (((unsigned long long) pow(2, i)) - 1)) + 1;
            classicSearchValueInFloorList(myList, searchValue);
        }
        stopTimer();

        // Affiche le temps écoulé
        printf("%s\n", getTimeAsString());

        // Ferme le fichier "classicSearch.txt"
        fclose(f);

        // Redirige la sortie standard vers un fichier "levelSearch.txt"
        FILE *f2 = freopen("levelSearch.txt", "a", stdout);

        // Affiche la taille de la liste
        printf("%d; ", i);

        // Mesure le temps pour effectuer 10 000 recherches en utilisant plusieurs niveaux dans la liste
        startTimer();
        for (int j = 0; j < 10000; ++j) {
            unsigned long long searchValue = (getLongRandomNumber() % (((unsigned long long) pow(2, i)) - 1)) + 1;
            levelSearchValueInFloorList(myList, searchValue);
        }
        stopTimer();

        // Affiche le temps écoulé
        printf("%s\n", getTimeAsString());

        // Ferme le fichier "levelSearch.txt"
        fclose(f2);

        // Libère la mémoire de la liste
        deleteFloorList(myList);
    }

    return 0;
}

