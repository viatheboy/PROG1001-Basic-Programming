//
//  oppg28.c
//  C_Prog
//
//  Created by Steffen Martinsen on 27/10/2022.
//

#include <stdio.h>
#include <string.h>


struct Ansatt {
    int     ansattNr;
    float   lønn;
    char    navn[80];
};

struct Ansatt skriv(const int ansatt, const struct Ansatt);

/**
 * Hovedprogram
 */
int main() {
    struct Ansatt ansatt1 = { 149, 459400.200, "Terje Ringeren" };
    struct Ansatt ansatt2;
    
    printf("Skriv inn ansattes navn: ");
    scanf(" %s", ansatt2.navn);         getchar();
    printf("Skriv inn ansattes ansattNr: ");
    scanf(" %i", &ansatt2.ansattNr);    getchar();
    printf("Skriv inn ansattes lønn: ");
    scanf(" %f", &ansatt2.lønn);        getchar();
    
    printf("Ansatt nr %i sitt navn: %s\nLønn: %.2f\n", ansatt1.ansattNr, ansatt1.navn, ansatt1.lønn);
    printf("Ansatt nr %i sitt navn: %s\nLønn: %.2f\n", ansatt2.ansattNr, ansatt2.navn, ansatt2.lønn);
    
    return 0;
}


struct Ansatt skriv(struct Ansatt ansatt1, struct Ansatt ansatt2) {
    
    struct Ansatt phAnsatt;
    
    // Kopierer over data til placeholder
    strcpy(phAnsatt.navn, ansatt1.navn);
    phAnsatt.lønn = ansatt1.lønn;
    phAnsatt.ansattNr = ansatt1.ansattNr;
    
    // Kopierer over ansatt 2 til ansatt 1
    strcpy(ansatt1.navn, ansatt2.navn);
    ansatt1.lønn = ansatt2.lønn;
    ansatt1.ansattNr = ansatt2.ansattNr;
    
    // Kopierer over fra placeholder til ansatt 2
    strcpy(ansatt2.navn, phAnsatt.navn);
    ansatt2.lønn = phAnsatt.lønn;
    ansatt2.ansattNr = phAnsatt.ansattNr;
    
    return ansatt1;
    return ansatt2;
    
}

