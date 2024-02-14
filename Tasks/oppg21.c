//
//  oppg21.c
//  C_Prog
//
//  Created by Steffen Martinsen on 05/10/2022.
//

#include <stdio.h>

// Deklarasjon av funksjon
void skrivTid(int time, int min, int sek);      // Tar inn tid.

int main (void) {
    
    skrivTid(14, 9, 59);
    skrivTid(25, 44, 11);
    skrivTid(5, 59, 2);
    
    return 0;
}


void skrivTid(int time, int min, int sek) {
    
    int timeTilMin, minTilSek, totalSek;
    
    if ((time >= 0 && time <= 24) && (min >= 0 && min <= 60) && (sek >= 0 && sek <= 60)) {
        // Skriver 0 foran timen om den er mindre enn 10
        if (time < 10)
            printf("Tiden er: 0%i:", time);
        else
            printf("Tiden er: %i:", time);
        
        // Skriver 0 foran minuttet om det er mindre enn 10
        if (min < 10)
            printf("0%i:", min);
        else
            printf("%i:", min);
        
        // Skriver 0 foran sekundet om det er mindre enn 10
        if (sek < 10)
            printf("0%i.\n\n", sek);
        else
            printf("%i.\n\n", sek);
        
        timeTilMin = time * 60;
        minTilSek = timeTilMin * 60;
        totalSek = sek + minTilSek;
        
        printf("Totalt antall sekunder: %i.\n\n", totalSek);
        
    } else
        printf("Ugyldig(e) verdi(er).\n\n");
}
