#include "acronym.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isletter(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return 1;
    else return 0;
}

char capital(char c) {
    if (c >= 'a' && c <= 'z') return c - 32;
    else return c;
}

char* abbreviate(char* string) {
    if (string == NULL) return NULL;
    char* abbrev = malloc(strlen(string) * sizeof(char));
    int letters = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if (isletter(string[i])) {
            letters += snprintf(abbrev+letters, 1, "%c", capital(string[i]));
            printf("\nLetters: %i Abbrev: %s Current %c", letters, abbrev, string[i]);
            i++;
            while (isletter(string[i]) && string[i] != '\0') i++; 
        }
    }
    char* final = malloc(letters * sizeof(char));
    for (int i = 0; i <= letters; i++) snprintf(final+i, 1, "%c", abbrev[i]);  
    free(abbrev);
    return final;
}
