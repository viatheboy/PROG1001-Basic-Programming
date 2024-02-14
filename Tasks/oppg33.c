//
//  oppg33.c
//  C_Prog
//
//  Created by Steffen Martinsen on 08/11/2022.
//

#include <stdio.h>

int finnLengde(const char* tp);
char* finnLengsteTekst(const char* tp, const char* tp2);

int main() {
    char tekst[20] = "Hallo du.";
    char tekst2[30] = "Hei jeg er lenger enn deg.";
    
    printf("Lengden på tekst: %i\n", finnLengde(tekst));
    
    printf("Lengste tekst er: %s\n", finnLengsteTekst(tekst, tekst2));
    printf("Og den er %i bokstaver lang.\n", finnLengde(finnLengsteTekst(tekst, tekst2)));
    
    return 0;
}

/**
 * Funksjon som finner lengden til en tekst.
 *
 *@param tp - Teksten som blir målt
 *
 *@return Midlertidig variabel som lagrer lengden i tallverdi
 */
int finnLengde(const char* tp) {
    int lengde = 0;
    
    // DETTE VAR HELT AVGJØRENDE, KUNNE IKKE VÆRE != '\0'
    while(*tp) {
        lengde++;
        *tp++;
    }
    return lengde;
}

/**
 * Funksjon som sammenligner to tekster og returnerer den lengste
 *
 *@see finnLengde
 * 
 *@param tp - Peker som peker til den første teksten
 *@param tp2 - Peker som peker til den andre teksten
 *
 *@return Returnerer pekeren som peker på den lengste teksten
 */
char* finnLengsteTekst(const char* tp, const char* tp2) {
    int lengde1;
    int lengde2;
    
    // Finner lengden til tekst 1
    lengde1 = finnLengde(tp);
    
    // Finner lengden til tekst 2
    lengde2 = finnLengde(tp2);
    
    // If statement som returnerer den lengste teksten
    if (lengde1 > lengde2)
        return tp;
    else if (lengde2 > lengde1)
        return tp2;
    else
        return 0;
}
