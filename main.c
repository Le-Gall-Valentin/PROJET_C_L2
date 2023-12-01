#include "Contact.h"
#include "ListOfFloorCells.h"
#include "manageCommands.h"
#include <stdio.h>

int main() {
    unsigned short state = 1;
    unsigned short autoComplete = 0;
    ListOfFloorCells *agenda = createEmptyFloorList(4);
//    FILE *fp;
//    fp = fopen("file.txt", "r");
//    if (fp == NULL) {
//        printf("marche pas");
//        return 1;
//    }
//    char line[MAX_BUFFER];
//    while (fgets(line, MAX_BUFFER, fp)) {
//        for (int i = 0; line[i] != '\0'; ++i) {
//            if (line[i] == ' ' || line[i] == '\n') {
//                line[i] = '\0';
//            }
//        }
//        addSortedCellInFloorList(agenda, createContact(line));
//    }
////    char *line;
////    unsigned int alloc = 0;
////    char c;
////    while (c != EOF) {
////        c = fgetc(fp);
////        line = (char *) realloc(line, (alloc + 1) * sizeof(char));
////        if (c == '\n') {
////            line[alloc] = '\0';
////            addSortedCellInFloorList(agenda, createContact(line));
////            alloc = 0;
////        } else {
////            line[alloc] = c;
////            alloc++;
////        }
////    }
//
//    fclose(fp);
    while (state) {
        char *entry;
        printf(">");
        entry = scanString();
        makeCommand(entry, &state, &autoComplete, agenda);
    }
    return 0;
}
