/**
 * Program som benytter funksjoner for å lese inn prestasjoner på en runde golf.
 * Programmet leser inn antall par per hull, antall slag spilleren slo på et hull, dette gjøres om
 * til en prestasjon (Bogey, Birdie etc), og spillerens totale sum summeres og skrives ut.
 * I tillegg, summeres og skrives par-antallet på hele golfbanen ut.
 */

#include <stdio.h>

#define ANTHULL      18   ///< Antall hull på golfbanen.
#define ANTUTRYKK     9   ///< Antall ulike uttrykk for slagprestasjoner.
#define STRLEN       15   ///< Maks tekstlengde.
const int MAXSLAG   = 8;  ///< Maks antall slag på hvert hull.

///< Liste over uttrykk for å forklare golfprestasjoner.
const char uttrykk[ANTUTRYKK][STRLEN] =
    { "Triple Bogey", "Double Bogey", "Bogey", "Par", "Birdie",
    "Eagle", "Albatross", "Kondor", "Hole-in-one" };


int  finnUttrykk(const int slag, const int par);
void lesPar();
void lesSlag();
int  lesTall(const int min, const int max);
void skrivPrestasjon();
void skrivSlag();
int  summer(const int arr[], const int n);


int  gPar[ANTHULL];
int  gSlag[ANTHULL];

/**
 * Hovedprogram
 */
int main () {
    lesPar();
    lesSlag();
    skrivSlag();
    skrivPrestasjon();
    
    printf("Banens par:       %i\n", summer(gPar, ANTHULL));
    printf("Spillerens total: %i\n", summer(gSlag, ANTHULL));
    
    return 0;
}

/**
 * Funksjon som skriver vurderer om et tall er gjennom to gitte verdier.
 *
 * @param   min - Minste verdi tallet kan være.
 * @param   max - Største verdi tallet kan være.
 *
 * @return  Returnerer tall mellom de to gitte verdiene.
 */
int lesTall(const int min, const int max) {
    int tall = 0;
    
    // Sørger for at tallet befinner seg innenfor det godkjente intervallet.
    do {
        printf("(Tall mellom %i-%i): ", min, max);
        scanf(" %i", &tall);    getchar();
    } while (tall < min || tall > max);
    
    return tall;
}

/**
 * Funksjon som leser inn antall par-slag per hull for alle 18 hull.
 *
 * @see lesTall(...)
 */
void lesPar() {
    
    // Leser inn par-slag per hull for alle hull.
    printf("Skriv inn par-slag for hver bane: \n");
    for (int i = 0; i < ANTHULL; i++) {
        printf("\tHull nr. %2i: ", i+1);
        gPar[i] = lesTall(1, MAXSLAG);
    }
}

/**
 * Funksjon som leser inn antall reelle slag per hull for alle 18 hull.
 *
 * @see lestall(...)
 */
void lesSlag() {
    printf("\nAntall aktuelle/reelle slag brukt pr. bane:\n");
    for (int i = 0; i < ANTHULL; i++) {
        printf("\tHull nr. %2i: ", i+1);
        gSlag[i] = lesTall(1, gPar[i]+3);
    }
}

/**
 *  Funksjon som finner indeksen i listen "uttrykk" basert på prestasjonen til spilleren.
 *  Indeksen er funnet ved par - slag.
 *
 *@param    slag - antall slag som ble slått av spilleren.
 *@param    par   - antall slag forventet av en gjennomsnittlig spiller.
 *
 *@return   indeksverdien som settes inn i listen "uttrykk".
 */
int finnUttrykk(const int slag, const int par) {
    
    // Avgjør hvilken indeks som returneres basert på prestasjon
    if (slag == 1)
        return 8;
    
    switch (slag - par) {
        case  3:    return 0; break;
        case  2:    return 1; break;
        case  1:    return 2; break;
        case  0:    return 3; break;
        case -1:    return 4; break;
        case -2:    return 5; break;
        case -3:    return 6; break;
        case -4:    return 7; break;
        
    }
    return 0;
}

/**
 * Funksjon som skriver ut par-antallet og reelt/aktuelt antall slag utført av spilleren på alle 18 hull.
 */
void skrivSlag() {
    
    printf("\nOversikt over alle slagene på alle hullene:\n");
    for (int i = 0; i < ANTHULL; i++) {
        printf("Hull nr.%2i: (Par: %i)\t%i slag - %s\n",
        i+1, gPar[i], gSlag[i], uttrykk[finnUttrykk(gSlag[i], gPar[i])]);
    }
}

/**
 * Funksjon som finner antall forekomster av hver prestasjon.
 *
 *@see finnUttrykk(...)
 */
void skrivPrestasjon() {
    
    // Lager variabler for å holde antall forekomster.
    int antForekomster[ANTUTRYKK] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    char pling = '\a';
    
    // Finner antall forekomster av prestasjonene.
    for (int i = 0; i < ANTHULL; i++) {
        switch (finnUttrykk(gSlag[i], gPar[i])) {
            case 0:     antForekomster[0]++; break;
            case 1:     antForekomster[1]++; break;
            case 2:     antForekomster[2]++; break;
            case 3:     antForekomster[3]++; break;
            case 4:     antForekomster[4]++; break;
            case 5:     antForekomster[5]++; break;
            case 6:     antForekomster[6]++; break;
            case 7:     antForekomster[7]++; break;
            case 8:     antForekomster[8]++; break;
        }
    }
    if (antForekomster[8] > 0)
        printf("%c", pling);
    printf("\nAntall forekomster av ulike prestasjoner: \n");
    for (int i = 0; i < ANTUTRYKK; i++) {
        printf("\t%14s: %i\n", uttrykk[i], antForekomster[i]);
    }
}

/**
 * Funksjon som summerer alle forekomstene i en array.
 *
 *@param    arr[] - summerer elementene i denne arrayen.
 *@param    n          - antall runder løkken i funksjonen skal iterere.
 */
int summer(const int arr[], const int n) {
    
    // Variabel som holder verdien som returneres.
    int antall = 0;
    
    // Løkke for å summere.
    for (int i = 0; i < n; i++) {
        antall += arr[i];
    }
    return antall;
}
