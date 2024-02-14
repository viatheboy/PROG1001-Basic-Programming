/*
Skriv et program som vha. pekere allokerer memory til både en int- og char-array som begge inneholder 25 elementer (indeks nr. 0-24). 
Fyll hele heltallsarrayen med noen passende tallverdier, og skiv ut dens innhold på skjermen. 
Fyll også hele tegnarrayen med noen passende tegn, avslutt med ‘\0’. Skriv ut dens innhold som en tekst.
Husk å frigi all allokert memory ifm. begge arrayene. Alle steder du har behov for å bruke verdien ‘25’ - bruk en const for dette.
*/

#include <stdio.h>
#include <stdlib.h>

#define ARRLENGDE 25 ///< Lengde på arrayene våre

int main () {
    int *intArr[ARRLENGDE];
    char* charArr[ARRLENGDE];

    for (int i = 0; i < ARRLENGDE; i++) {
        intArr[i] = (int*) malloc(sizeof(int));
        *intArr[i] = (i+1) * 2;
    }

    for (int i = 0; i < ARRLENGDE; i++) {
        printf("%i ", *intArr[i]);
    }

    intArr[ARRLENGDE-1] = (int*) malloc(ARRLENGDE * sizeof(int));
    printf("\n");

    for (int i = 0; i < ARRLENGDE-1; i++) {
        charArr[i] = (char*) malloc(sizeof(char));
    }

    charArr[ARRLENGDE-1] = "Hello dude.\0";
    
    printf("%s\n", charArr[ARRLENGDE-1]);

    free(intArr[ARRLENGDE-1]);

    free(charArr[ARRLENGDE]);

    // Skjønner ikke helt hvorfor nettopp dette går, og hvorfor vi ikke trenger å sette -1 her. 
    return 0;

}

