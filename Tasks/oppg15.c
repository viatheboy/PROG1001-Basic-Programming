//
//  oppg15.c
//  C_Prog
//
//  Created by Steffen Martinsen on 19/09/2022.
//

#include <stdio.h>

int main(void) {
    
    int tall1;
    int tall2;
    int addert;
    int subtrahert;
    int multiplisert;
    char valg;
    
    do {
        printf("Vennligst skriv inn et tall: ");
        scanf("%i", &tall1);
        printf("Vennligst skriv inn enda et tall: ");
        scanf("%i", &tall2);
        
        addert = tall1 + tall2;
        subtrahert = tall1 - tall2;
        multiplisert = tall1 * tall2;
        
        printf("Disse tallene addert er: %i\n", addert);
        printf("Disse tallene subtrahert er: %i\n", subtrahert);
        printf("Disse tallene multiplisert er: %i\n", multiplisert);
        
        printf("Vil du fortsette denne leken?\n");
        printf("y/n\n");
        scanf(" %c", &valg);
    } while (valg == 'y');
    
    
    return 0;
}
