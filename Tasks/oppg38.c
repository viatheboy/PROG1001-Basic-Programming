/*
Filen ‘BAATER.DTA’ har følgende format for hver post (seks felter på to linjer):
<reg.nr for/på båten> <årsmodell> <hestekrefter> <telefonnummer> <eiers navn> <båtens modelltype>
<reg.nr> er en tekst uten blanke i. Både <eiers navn> og <båtens modelltype> består av flere ord (med blanke mellom). 
De tre andre verdiene er int.
Skriv et program som:
• inneholder en struct-variabel for å lagre alle de seks dataene fra en post om en båt.
(Denne ene structen blir stadig fylt med nye data, ettersom at dataene om en og en
båt leses inn fra filen.)
• leser inn alle dataene om en og en båt fra den angitte filen
• for hver innlesning skriver ut de for øyeblikket lagrede dataene i struct-variabelen
Bruk funksjoner for selve filinnlesningen og skjermutskriften ifm. en struct (akkurat som i EKS_38.c).
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define CHARLENGDE 80
#define MAXBÅT 4


struct Båt {
    int listeNr;
    char regNr[CHARLENGDE];
    int årsmodell; 
    int hestekrefter;
    int tlfNr;
    char navn[CHARLENGDE];
    char type[CHARLENGDE];
};


void båtLesFraFil(FILE* inn, struct Båt* båt, const int n);
void båtSkrivData(const int nr, const struct Båt* båt);


struct Båt* gBåter[MAXBÅT]; ///< Alle båter lest inn fra fil.
int gAntallBåter = 0;       ///< Antall båter som er lest inn. 


int main() {
    int nr; 

    FILE* innfil;

    printf("\n\nLeser inn fra filen 'BÅT.txt' ......\n\n\n");

    innfil = fopen("BAATER.txt", "r");

    if (innfil) {

        fscanf(innfil, "%i", &nr);

        while (!feof(innfil) && gAntallBåter < MAXBÅT) {
            gBåter[gAntallBåter] = (struct Båt*) malloc(sizeof(struct Båt));

            båtLesFraFil(innfil, gBåter[gAntallBåter], nr);
            gAntallBåter++;
            fscanf(innfil, "%i", &nr);
        }

    } else {
        printf("Finner ikke filen.\n");
    }
    
    fclose(innfil);


    for (int i = 0; i < gAntallBåter; i++) {
        båtSkrivData(i+1, gBåter[i]);
    }
}


/**
 * Leser alle data om en båt fra fil.
 * 
 * @param inn - filen det skal leses fra.
 * @param båt - Structen som skal få sine verdier innlest. 
 */
void båtLesFraFil(FILE* inn, struct Båt* båt, const int n) {
    båt->listeNr = n;
    fgets(båt->regNr, CHARLENGDE, inn);
    fscanf(inn, "%i %i %i", &(båt->årsmodell), &(båt->hestekrefter), &(båt->tlfNr));
    getc(inn);
    fgets(båt->navn, CHARLENGDE, inn);
    fgets(båt->type, CHARLENGDE, inn);
}

void båtSkrivData(const int nr, const struct Båt* båt) {
    printf("\nNr: %i\n", båt->listeNr);
    printf("RegNr: %s\nÅrsmodell: %i\n", båt->regNr, båt->årsmodell);
    printf("HK: %i\nTlfNr: %i\n", båt->hestekrefter, båt->tlfNr);
}