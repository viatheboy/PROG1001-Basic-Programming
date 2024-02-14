//
//  oppg11.c
//  C_Prog
//
//  Created by Steffen Martinsen on 19/09/2022.
//

#include <stdio.h>

/// Hovedprogram
int main(void) {
    
    int tall[5];
    int tall2[] = {6, 2, 10, 12, 19, 3, 7};
    
    char tekst[5];
    char navn[] = "Lars Hansen";
    char adresse[] = "Ringgata 111";

    // Legger inn verdier i de to første elementene i tall
    tall[0] = 13;
    tall[1] = 67;
    
    // Summerer disse to tallene og legger det i tall tre
    tall[2] = tall[0] + tall[1];
    printf("Tall tre: %i\n", tall[2]);
    
    // Halverer verdien i tall tre
    tall[2] /= 2;
    printf("Tall tre halvert: %i\n", tall[2]);
    
    // Legger summen av de første tre i tall 2 til det fjerde i tall
    tall[3] = tall2[0] + tall2[1] + tall2[2] + tall2[3];
    
    // Legger summen av de tre siste i tall2 i til det femte i tall
    tall[4] = tall2[6] + tall2[5] + tall2[4];
    
    printf("Tall fire: %i\n", tall[3]);
    printf("Tall fem: %i\n", tall[4]);
    
    // Øker verdien i tall tre fire ganger
    tall[2]++;
    tall[2]++;
    tall[2]++;
    tall[2]++;
    
    printf("Tall tre: %i\n", tall[2]);
    
    // Legger inn verdier i tekst
    tekst[1] = 'A';
    tekst[3] = 'E';
    tekst[0] = navn[5];
    tekst[2] = navn[0];
    
    printf("Kua har %c%c%c%c\n", tekst[0], tekst[1], tekst[2], tekst[3]);
    printf("%c%c%c\n", adresse[9], adresse[10], adresse[11]);
    printf("%s\n", navn);
    printf("%s\n", adresse);
    
    
    return 0;
}
