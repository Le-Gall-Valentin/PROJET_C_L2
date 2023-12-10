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