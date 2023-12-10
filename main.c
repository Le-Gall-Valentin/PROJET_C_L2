#include "Contact.h"
#include "ListOfFloorCells.h"
#include "manageCommands.h"
#include <stdio.h>

int main() {
    unsigned short state = 1;
    unsigned short autoComplete = 0;
    ListOfFloorCells *agenda = createEmptyFloorList(4);
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
