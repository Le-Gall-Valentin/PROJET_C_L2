#include "Contact.h"
#include "ListOfFloorCells.h"
#include "manageCommands.h"
#include <stdio.h>

int main() {
    unsigned short state = 1;
    unsigned short autoComplete = 0;
    ListOfFloorCells *agenda = createEmptyFloorList(4);
//    FILE *fp;
//    fp = fopen("noms2008nat_txt.txt", "r");
//    if (fp == NULL) {
//        printf("marche pas");
//        return 1;
//    }
//    char line[MAX_BUFFER];
//    while (fgets(line, MAX_BUFFER, fp)) {
//        for (int i = 0; line[i] != '\0'; ++i) {
//            if (line[i] == '\n') {
//                line[i] = '\0';
//            }
//        }
//        addSortedCellInFloorList(agenda, createContact(line));
//    }
//    fclose(fp);
    while (state) {
        char *entry;
        do {
            printf(">");
            entry = scanString();
        } while (entry == NULL);
        makeCommand(entry, &state, &autoComplete, agenda);
    }
    return 0;
}
