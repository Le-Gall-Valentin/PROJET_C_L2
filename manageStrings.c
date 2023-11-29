//
// Created by hugol on 23/11/2023.
//

#include "manageString.h"

void deleteString(char *string) {
    free(string);
    string = NULL;
}

unsigned int countStringArrayElements(const char *array, const char *delimiter) {
    unsigned int count = 1;
    size_t delimiterLength = strlen(delimiter);
    char const *temporary = array;
    while (*temporary != '\0') {
        if (strncmp(temporary, delimiter, delimiterLength) == 0) {
            count++;
            temporary += delimiterLength;
        } else {
            temporary++;
        }
    }
    return count;
}

void copySubString(char *destination, const char *source, size_t length) {
    for (int i = 0; i < length; i++) {
        destination[i] = source[i];
    }
    destination[length] = '\0';
}

StringArray splitStringToArray(const char *stringToSplit, const char *delimiter) {
    StringArray result;
    size_t delimiterLength = strlen(delimiter);
    result.size = countStringArrayElements(stringToSplit, delimiter);
    result.array = (char **) malloc(sizeof(char *) * result.size);
    if (result.array == NULL) {
        result.size = 0;
    } else {
        unsigned int lineIndex = 0;
        const char *temporary = stringToSplit;
        const char *temporaryStart = stringToSplit;
        while ((*temporary != '\0') && (lineIndex < result.size)) {
            if (strncmp(temporary, delimiter, delimiterLength) == 0) {
                size_t subStringLength = temporary - temporaryStart;
                result.array[lineIndex] = (char *) malloc(sizeof(char) * (subStringLength + 1));
                copySubString(result.array[lineIndex], temporaryStart, subStringLength);
                lineIndex++;
                temporary += delimiterLength;
                temporaryStart = temporary;
            } else {
                temporary++;
            }
        }
        if (lineIndex < result.size) {
            size_t subStringLength = temporary - temporaryStart;
            result.array[lineIndex] = (char *) malloc(sizeof(char) * (subStringLength + 1));
            copySubString(result.array[lineIndex], temporaryStart, subStringLength);
        }
    }

    return result;
}

int isDigit(char *string) {
    int digit = TRUE;
    for (int i = 0; i < strlen(string); i++) {
        if ((string[i] < 48) || (string[i] > 57)) {
            digit = FALSE;
        }
    }
    return digit;
}

int convertStringToDigit(char *string) {
    if (isDigit(string)) {
        return atoi(string);
    }
    return 0;
}

char *scanString(void) {
    char *text;
    scanf("%m[^\n]", &text);
    fflush(stdin);
    return text;
}

void toLowerCase(char *string) {
    unsigned long long size = strlen(string);
    for (int i = 0; i < size; i++) {
        if (string[i] <= 'Z' && string[i] >= 'A') {
            string[i] = string[i] + 32;
        }
    }
}

void printGapChar(char *name) {
    unsigned long long lenOfValue = strlen(name);
    for (int i = 0; i < lenOfValue; ++i) {
        printf("-");
    }
    printf("---------");
}
