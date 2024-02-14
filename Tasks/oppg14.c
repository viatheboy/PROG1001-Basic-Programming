//
//  oppg14.c
//  C_Prog
//
//  Created by Steffen Martinsen on 19/09/2022.
//

#include <stdio.h>

int main(void) {
    
    int tall;
    int antallLest = 0;
    int totalSum = 0;
    int gjennomsnitt = 0;
    
    printf("Skriv inn et positivt heltall: ");
    scanf("%i", &tall);
    antallLest++;
    totalSum += tall;
    
    // Loop som gjentar seg selv så lenge innlest tall er større enn 0
    while (tall > 0) {
        printf("Skriv inn et positivt heltall: ");
        scanf("%i", &tall);
        antallLest++;
        totalSum += tall;
    }

    printf("Total antall innlesninger: %i\n", antallLest);
    printf("Summen av innleste tall: %i\n", totalSum);
    printf("Gjennomsnittet av innleste tall: %i\n", totalSum/antallLest);
    
    return 0;
}
