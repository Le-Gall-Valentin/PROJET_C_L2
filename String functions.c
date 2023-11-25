//
// Created by hugol on 23/11/2023.
//

#include "String functions.h"


char *scanString(void){
    char* text;
    scanf("%m[^\n]",&text);
    return text;
}

void toLowerCase(char *string) {
    unsigned long long size = strlen(string);
    for(int i=0; i<size;i++){
        if(string[i]<='Z' && string[i] != '_'){
            string[i] = string[i]+32;
        }
    }
}
