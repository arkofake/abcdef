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

// char* abbreviate(char* string) {
//     if (string == NULL) return NULL;
//     char* abbrev = malloc(strlen(string) * sizeof(char));
//     int letters = 0;
//     for (int i = 0; string[i] != '\0'; i++) {
//         if (isletter(string[i])) {
//             //letters += snprintf(abbrev+letters, 1, "%c", capital(string[i]));
//             abbrev[letters] = string[i];
//             letters++;
//             // printf("\nLetters: %i Abbrev: %s Current %c", letters, abbrev, string[i]);
//             i++;
//             while (isletter(string[i]) && string[i] != '\0') i++; 
//         }
//         else continue;
//     }
//     return abbrev;
// }

char* abbreviate(char* string) {
    if (string == NULL || !(strlen(string))) return NULL;
    char* abbrev = malloc(strlen(string) * sizeof(char));
    int letters = 0;
    int i = 0;
    while (string[i] != '\0') {
        if (isletter(string[i])) {
            sprintf(abbrev+letters, "%c", capital(string[i]));
            letters++;
            i++;
            while (isletter(string[i]) && string[i] != '\0') i++; 
        }
        else i++;
    }
    return abbrev;
}
