//
//  Oppg31.c
//  C_Prog
//
//  Created by Steffen Martinsen on 03/11/2022.
//

#include <stdio.h>

struct Person {
    char navn[80];
    char skoleklasse;
    int  skonummer;
};

int main() {
    struct Person person1;
    struct Person* pp;

    pp = &person1;
    
    printf("Skriv inn personens navn: ");
    scanf(" %s", pp->navn); getchar();
    
    do {
        printf("Skriv inn personens skoleklasse (A-Z): ");
        scanf(" %c", &pp->skoleklasse); getchar();
    } while (pp->skoleklasse < 'A' || pp->skoleklasse > 'Z');

    printf("Skriv inn personens skonummer: ");
    scanf("%i", &pp->skonummer);
    
    printf("pp->navn: %s\n", pp->navn);
    printf("pp->skoleklasse: %c\n", pp->skoleklasse);
    printf("pp->skonummer: %i\n\n", pp->skonummer);
    
    printf("person1.navn: %s\n", person1.navn);
    printf("person1.skoleklasse: %c\n", person1.skoleklasse);
    printf("person1.skonummer: %i\n", person1.skonummer);
    
    return 0;
}
