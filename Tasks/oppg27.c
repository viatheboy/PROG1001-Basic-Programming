//
//  oppg27.c
//  C_Prog
//
//  Created by Steffen Martinsen on 27/10/2022.
//

#include <stdio.h>
#include <string.h>

float lesTall(const char tekst[], const int min, const int max);
void lesTekst(const char ledetekst[], char tekst []);

struct Person {
    char  navn[80];
    int   alder;
    float vekt;
};

/**
 * Hovedprogram
 */
int main () {
    struct Person folk[10];
    int antallFolk;
    int totalAlder = 0;
    float totalVekt = 0;
    struct Person eldst;
    int eldstNummer;
    
    antallFolk = lesTall("Hvor mange personer?", 1, 10);
    
    for (int i = 0; i < antallFolk; i++) {
        printf("(Data for person nr. %i)\n", i+1);
        lesTekst("Skriv in personens navn: ", folk[i].navn);
        folk[i].alder = lesTall("Skriv inn personens alder", 1, 120);
        folk[i].vekt = lesTall("Skriv inn personens vekt", 20, 150);
        totalAlder += folk[i].alder;
        totalVekt += folk[i].vekt;
    }
    
    printf("Total alder for alle innleste er: %i\n", totalAlder);
    printf("Gjennonsnittsvekt for personene er: %.2f\n", totalVekt/antallFolk);
    
    eldst.alder = 0;
    
    for (int i = 0; i < antallFolk; i++) {
        if (folk[i].alder > eldst.alder) {
            eldst.alder = folk[i].alder;
            strcpy(eldst.navn, folk[i].navn);
            eldstNummer = i;
        }
    }
    
    printf("Den eldste personen er nummer %i i listen\nNavn: %s\nAlder: %i\n", eldstNummer, eldst.navn, eldst.alder);
    
    
    return 0;
}

float lesTall(const char tekst[], const int min, const int max) {
    float tall;
    
    do {
        printf("%s (%i-%i): ", tekst, min, max);
        scanf(" %f", &tall);
    } while (tall < min || tall > max);
    
    return tall;
}

void lesTekst(const char ledetekst[], char tekst[]) {
    printf("%s", ledetekst);
    scanf(" %s", tekst);
}
