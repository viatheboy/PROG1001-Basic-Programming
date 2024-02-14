/**
 * Program som leser inn data for skiskyttere og skirenn. Kan også skrive ut informasjon om
 * alle skiskytterne, eller skrive ut informasjom om alle eller ett skirenn.
 * Programmet allokerer minne ved bruk og frigir dette minnet når det er blitt overflødig.
 */

#include <stdio.h>
#include <stdbool.h>
#include "LesData.h"


#define MAXUTOVER   100 ///< Max. antall skiskytterutøvere.
#define MAXRENN     30  ///< Max. antall renn i løpet av en sesong.
#define MINUTOVER   2   ///< Min. antall skiskytterutøvere.


/**
 * Enum med aktuelle øvelser for skiskytterrennene.
 */
enum Ovelse {Jakstart, Normaldistanse, Sprint};


/**
 * En skiskytter med navn og antall skudd og treff.
 */
struct Skiskytter {
    char* navn;
    int   treffTotalt;
    int   skuddTotalt;
};


/**
 * Et skirenn på et sted, av en type, antall skudd og resultatliste.
 */
struct Skirenn {
    char* sted;
    enum  Ovelse type;
    int   antSkudd;
    int   antDeltakere;
    int   resultatliste[MAXUTOVER];
};


void frigiAllokertMemory();
void leggTilSkiskytter();
void leggTilSkirenn();
void skirennFrigi(struct Skirenn* r);
void skirennLesData(struct Skirenn* r);
void skirennSkrivBasis(const struct Skirenn* r);
void skirennSkrivData(const struct Skirenn* r);
void skiskytterFrigi(struct Skiskytter* s);
void skiskytterLesData(struct Skiskytter* s);
void skiskytterSkrivData(const struct Skiskytter* s);
void skiskytterSkrivNavn(const struct Skiskytter* s);
void skiskytterTreff(struct Skiskytter* s, const int skudd, const int treff);
void skrivAlleSkirenn();
void skrivEttSkirenn();
void skrivAlleSkiskyttere();
void skrivMeny();


struct Skiskytter* gSkiskyttere[MAXUTOVER];   ///< Alle skiskytterne.
int    gAntSkiskyttere = 0;                   ///< Aktuelt nåværende antall.
struct Skirenn* gSkirennene[MAXRENN];         ///< Alle rennene.
int    gAntSkirenn = 0;                       ///< Aktuelt nåværende antall.


/**
 * Hovedprogram
 */
int main () {
    char kommando;

    skrivMeny();
    kommando = lesChar("\nKommando");

    while (kommando != 'Q')  {
      switch (kommando)  {
        case 'S':  leggTilSkiskytter();     break;
        case 'R':  leggTilSkirenn();        break;
        case 'A':  skrivAlleSkirenn();      break;
        case 'E':  skrivEttSkirenn();       break;
        case 'P':  skrivAlleSkiskyttere();  break;
        default:   skrivMeny();             break;
      }
      kommando = lesChar("\nKommando");
    }

    frigiAllokertMemory();

    return 0;
}


/**
 * Funksjon som frigir alt allokert memory.
 *
 *@see
 */
void frigiAllokertMemory() {
    // Loop for å frigi minne til alle skiskytterne + selve structen
    for (int i = 0; i < gAntSkiskyttere; i++) {
        skiskytterFrigi(gSkiskyttere[i]);
        free(gSkiskyttere[i]);
    }
    // Loop for å frigi minne til alle skirenne + selve structen
    for (int i = 0; i < gAntSkirenn; i++) {
        skirennFrigi(gSkirennene[i]);
        free(gSkirennene[i]);
    }
}


/**
 * Funksjon som legger til ny skiskytter. Gir beskjed om max antall skyttere er overskredet.
 *
 *@see skiskytterLesData(...)
 */
void leggTilSkiskytter() {
    if (gAntSkiskyttere >= MAXUTOVER)
        printf("Kan ikke legge til utøver. Max antall utøvere nådd.\n");
    else {
        printf("Utøvers nummer: %i\n", gAntSkiskyttere+1);
        
        gSkiskyttere[gAntSkiskyttere] = (struct Skiskytter*) malloc(sizeof(struct Skiskytter));
        skiskytterLesData(gSkiskyttere[gAntSkiskyttere]);
        gAntSkiskyttere++;
    }
}


/**
 * Funksjon som legger til et skirenn.
 *
 *@see skirennLesData(...)
 */
void leggTilSkirenn() {
   if (gAntSkirenn >= MAXRENN)
       printf("\nKan ikke legge til skirenn. Max antall skirenn overskredet.\n");
    else if (gAntSkiskyttere < MINUTOVER)
        printf("\nKan ikke legge til skirenn. Det må registreres minst to utøvere.\n");
    else {
        printf("\nSkirenn nummer: %i\n", gAntSkirenn+1);
        gSkirennene[gAntSkirenn] = (struct Skirenn*) malloc(sizeof(struct Skirenn));
        skirennLesData(gSkirennene[gAntSkirenn]);
        gAntSkirenn++;
    }
}


/**
 * Funksjon som frigir data allokert til structen.
 *
 *@param r - Skirennet det frigis data fra.
 */
void skirennFrigi(struct Skirenn* r) {
    free(r->sted);
}


/**
 * Funksjon som leser inn data for skirenn..
 *
 *@Param s - Skirennet det leses inn data for.
 *@see   skiskytterTreff(...)
 */
void skirennLesData(struct Skirenn* r) {
    int antTreff;
    
    r->sted = lagOgLesText("Sted");
  
    // Loop for å sikre at bruker skriver inn J, S, eller N
    do {
        r->type = lesChar("Type renn (S/J/N): ");
    } while (r->type != 'S' && r->type != 'J' && r->type != 'N');
    
    // If statement som avgjør verdien til antall skudd basert på renntype
    if (r->type == 'S') {
        r->type = Sprint;
        r->antSkudd = 10;
    } else if (r->type == 'J') {
        r->type = Jakstart;
        r->antSkudd = 20;
    } else {
        r->type = Normaldistanse;
        r->antSkudd = 20;
    }
    
    r->antDeltakere = lesInt("Antall deltakere: ", MINUTOVER, gAntSkiskyttere);
    
    // Loop for å avgjøre plasseringer i rennet.
    for (int i = 0; i < r->antDeltakere; i++) {
        printf("\n%i.plass:\n", i+1);
        r->resultatliste[i] = lesInt("Deltakernummer", 1, r->antDeltakere);
    }
    
    // Loop for å skrive inn antall treff per deltaker
    for (int i = 0; i < r->antDeltakere; i++) {
        printf("\nDeltakernummer. %i: \n", i+1);
        antTreff = lesInt("Antall treff", 0, r->antSkudd);
        skiskytterTreff(gSkiskyttere[i], r->antSkudd, antTreff);
    }
}


/**
 * Skriver ut basisdata for valgt skirenn.
 *
 *@param r - Skirenn det skrives ut data for.
 */
void skirennSkrivBasis(const struct Skirenn* r) {
    printf("Sted: \t\t%s\n", r->sted);
    if (r->type == Sprint)
        printf("Renntype: \tSprint\n");
    else if (r->type == Jakstart)
        printf("Renntype: \tJaktstart\n");
    else if (r->type == Normaldistanse)
        printf("Renntype: \tNormaldistanse\n");
}


/**
 * Skriver alle datamedlemmer til valgt skirenn.
 *
 *  @param   r  - Skirenn som ALLE dataene skrives ut for
 *  @see     skirennSkrivBasis(...)
 *  @see     skiskytterSkrivNavn(...)
 */
void skirennSkrivData(const struct Skirenn* r) {
    skirennSkrivBasis(r);
    printf("Antall skudd: %i\n", r->antSkudd);
    for (int i = 0; i < r->antDeltakere; i++) {
        printf("\n%i. Plass:\nDeltakernummer: %i\n", i+1, r->resultatliste[i]);
        skiskytterSkrivNavn(gSkiskyttere[r->resultatliste[i]-1]);
    }
}


/**
 * Frigir minne allokert til structen.
 *
 *@param s - Skiskytteren det frigis data fra.
 */
void skiskytterFrigi(struct Skiskytter* s) {
    free(s->navn);
}


/**
 * Funksjon som leser inn data til skiskytter.
 *
 *@param s - Structen som vi skriver data til.
 */
void skiskytterLesData(struct Skiskytter* s) {
    s->navn         = lagOgLesText("Navn");
    s->skuddTotalt  = 0;                   // Nullstiller verdiene
    s->treffTotalt  = 0;
}


/**
 * Funksjon som regner ut treffprosent og skriver ut navn og treffprosent for en gitt skiskytter.
 *
 *@Param s - Skiskytteren det skrives ut data om.
 */
void skiskytterSkrivData(const struct Skiskytter* s) {
    float treffprosent;
    if (s->skuddTotalt <= 0) {
        treffprosent = 0.00;
    } else {
        treffprosent = ((float) s->treffTotalt/(float) s->skuddTotalt) * 100;
    }
    
    printf("Navn: \t\t\t%s\n",     s->navn);
    printf("Treffprosent: \t%.2f\n", treffprosent);
}


/**
 * Funksjon som skrier ut navnet til en skiskytter.
 *
 *@Param s - Skiskytteren navnet skrives ut for.
 */
void skiskytterSkrivNavn(const struct Skiskytter* s) {
    printf("Navn: %s\n", s->navn);
}


/**
 * Regne ut treffprosent til en utøver.
 *
 *@param s          - Utøveren som skudd og treff endres for.
 *@param skudd - Total antall skudd i ETT renn.
 *@param treff - Total antall treff i ETT renn.
 */
void skiskytterTreff(struct Skiskytter* s, const int skudd, const int treff) {
    s->skuddTotalt += skudd;
    s->treffTotalt += treff;
}


/**
 * Funksjon som skriver ut data om alle skirenn
 *
 *@see skirennSkrivBasis(...)
 */
void skrivAlleSkirenn() {
    if (gAntSkirenn <= 0)
        printf("Finnes ingen skirenn å skrive ut.\n");
    else {
        for (int i = 0; i < gAntSkirenn; i++) {
            printf("\nSkirenn nr: %i\n", i+1);
            skirennSkrivBasis(gSkirennene[i]);
        }
    }
}


/**
 * Funksjon som skriver ut data om ett skirenn.
 *
 *@see skrivAlleSkirenn()
 *@see skirennSkrivData(...)
 */
void skrivEttSkirenn() {
    int rennummer;
    if (gAntSkirenn <= 0)
        printf("Finnes ingen skirenn å skrive ut.\n");
    else {
        printf("\nAlle skirenn: \n");
        skrivAlleSkirenn();
        rennummer = lesInt("\nRennummer", 1, gAntSkirenn);
        skirennSkrivData(gSkirennene[rennummer-1]);
    }
}


/**
 * Funksjon som skriver ut data om alle skiskyttere.
 *
 *@see skiskytterSkrivData(...)
 */
void skrivAlleSkiskyttere() {
    if (gAntSkiskyttere <= 0) {
        printf("Ingen skiskyttere å skrive data for.\n");
    } else {
        for (int i = 0; i < gAntSkiskyttere; i++) {
            printf("Deltaker nr. %i\n", i+1);
            skiskytterSkrivData(gSkiskyttere[i]);
        }
    }
}


/**
 *  Skriver ut menyen til programmet.
 */
void skrivMeny() {
    printf("\nTilgjengelige kommandoer:");
    printf("\n\tS - legg til ny Skiskytter");
    printf("\n\tR - legg til nytt skiRenn");
    printf("\n\tA - skriv Alle skirenn");
    printf("\n\tE - skriv Ett skirenn");
    printf("\n\tP - skriv Poeng til alle skiskyttere\n");
}
