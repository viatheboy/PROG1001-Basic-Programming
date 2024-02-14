//
//  oppg4.c
//  GrProg
//
//  Created by Steffen Martinsen on 29/08/2022.
//  Program for å skrive ut Navn, gateadresse, postnummer, poststed, telefonnummer, og alder.

#include <stdio.h>

int main(void) {
    
    // Variabler med heltall - postnummer, mobilnummer, og alder
    int postnummer = 2318;
    int mobilnummer = 92471296;
    int alder = 27;
    
    // Utskrift av data
    printf("Navn:\t\tSteffen\n");
    printf("Adresse:    Disenvegen 5A\n");
    printf("Poststed:\t%i, Hamar\n", postnummer);
    printf("Mobilnr:    %i\n", mobilnummer);
    printf("Alder:      %i\n\n\n\n", alder);
    
    return 0;
}
