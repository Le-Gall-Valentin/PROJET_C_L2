//
// Created by Le Gall on 15/11/2023.
//

#include "manageInts.h"

int lenOfInt(unsigned long long value) {
    // Initialisation de la longueur
    int len = 0;

    // Si la valeur est 0, sa longueur est 1
    if (value == 0) {
        return 1;
    }

    // Boucle while pour calculer la longueur de la valeur
    while (value >= 1) {
        value = value / 10;
        len++;
    }

    // Retourne la longueur calculée
    return len;
}

void printGap(unsigned long long value) {
    // Permet de garder le bon espacement entre les cellules à l'affichage
    int lenOfValue = lenOfInt(value);

    // Affiche une séquence de tirets équivalente à la longueur de la valeur
    for (int i = 0; i < lenOfValue; ++i) {
        printf("-");
    }

    // Affiche une séquence de tirets supplémentaires pour un espacement défini
    printf("---------");
}

unsigned long long getLongRandomNumber() {
    // Initialise une variable pour stocker la valeur aléatoire
    unsigned long long r = 0;

    // Utilise une boucle pour générer la valeur aléatoire en combinant plusieurs résultats de rand()
    for (int i = 0; i < 5; ++i) {
        // Décale la valeur existante de 15 bits vers la gauche (r << 15)
        // OR avec les 15 bits inférieurs du résultat de rand() (rand() & 0x7FFF)
        r = (r << 15) | (rand() & 0x7FFF);
    }

    // Garantit que la valeur générée est sur 64 bits en appliquant un masque
    return r & 0xFFFFFFFFFFFFFFFFULL;
}

unsigned int nbDivideBy2(int value) {
    // Initialise la variable résultat
    unsigned int result = 0;

    // Utilise une boucle while pour diviser la valeur par 2 jusqu'à ce qu'elle devienne impair ou atteigne zéro
    while (((value % 2) == 0) && (value != 0)) {
        value = value / 2;
        result++;
    }

    // Retourne le nombre de divisions effectuées
    return result;
}
