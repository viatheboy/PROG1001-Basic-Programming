//
//  oppg12.c
//  C_Prog
//
//  Created by Steffen Martinsen on 19/09/2022.
//

#include <stdio.h>

/// Const variabel for lengde på string-array
const STRLEN = 20;

/// Hovedprogram
int main(void) {
    
    int alder;
    float lengde;
    char forBokstav;
    char sisteBokstav;
    char forNavn[STRLEN];
    char etterNavn[STRLEN];
    
    printf("Skriv inn din alder: ");
    scanf("%i", &alder);
    printf("Skriv inn din høyde i meter: ");
    scanf("%f", &lengde);
    printf("Skriv inn hele navnet ditt: ");
    scanf("%s %s", forNavn, etterNavn);
    
    printf("Velkommen %s, %s\n", etterNavn, forNavn);
    printf("Du er %i år gammel, og din høyde er %.2f\n", alder, lengde);
    printf("Vi ser frem til å samarbeide med dem, Herr %c%c.", forNavn[0], etterNavn[0]);
    
}
