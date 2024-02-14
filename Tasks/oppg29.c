//
//  oppg29.c
//  C_Prog
//
//  Created by Steffen Martinsen on 28/10/2022.
//

#include <stdio.h>

struct  Brok lesBrok();
void    skrivBrok(const struct Brok b);
struct  Brok addisjon(const struct Brok b, const struct Brok b2);
struct  Brok subtraksjon(const struct Brok b, const struct Brok b2);
struct  Brok multiplikasjon(const struct Brok b, const struct Brok b2);
struct  Brok divisjon(const struct Brok b, const struct Brok b2);

struct Brok {
    int teller;
    int nevner;
};

/**
 * Hovedprogram
 */
int main () {
    struct Brok brok, brok2, svar;
    
    brok  = lesBrok();
    brok2 = lesBrok();
    
    // Oppdaterer svar og skriver ut brok + brok2
    svar = addisjon(brok, brok2);
    skrivBrok(brok); printf(" + "); skrivBrok(brok2);
    printf(" = "); skrivBrok(svar); printf("\n");
    
    // Oppdaterer svar og skriver ut brok - brok2
    svar = subtraksjon(brok, brok2);
    skrivBrok(brok); printf(" - "); skrivBrok(brok2);
    printf(" = "); skrivBrok(svar); printf("\n");
    
    // Oppdaterer svar og skriver ut brok * brok2
    svar = multiplikasjon(brok, brok2);
    skrivBrok(brok); printf(" * "); skrivBrok(brok2);
    printf(" = "); skrivBrok(svar); printf("\n");
    
    // Oppdaterer svar og skriver ut brøk / brok2
    svar = divisjon(brok, brok2);
    skrivBrok(brok); printf(" / "); skrivBrok(brok2);
    printf(" = "); skrivBrok(svar); printf("\n");
    
}

/**
 * Leser inn og returnerer en brøk, der teller er et hvilket som helst heltall, og nevner er et positivt heltall.
 */
struct Brok lesBrok() {
    struct Brok b;
    
    printf("Skriv inn teller: ");
    scanf("%i", &b.teller);
    
    do {
        printf("Skriv inn nevner (positivt heltall): ");
        scanf("%i", &b.nevner);
    } while (b.nevner <= 0);
    
    return b;
}


/**
 * Skriver parameterens data på formen teller/nevner
 *
 *@param    b - brøken det opereres på
 */
void skrivBrok(const struct Brok b) {
    printf("%i/%i", b.teller, b.nevner);
}

/**
 * Adderer/summerer to brøker og returnerer svaret
 */
struct Brok addisjon(const struct Brok b, const struct Brok b2) {
    struct Brok temp;
    
    temp.teller = (b.teller * b2.nevner) + (b.nevner * b2.teller);
    temp.nevner = b.nevner * b2.nevner;
    
    return temp;
}

/**
 * Subtraherer/trekker fra hverandre de to brøkene som er gitt og returnerer svaret
 *
 *@param b - første brøken
 *@param b2 - andre brøken
 */
struct Brok subtraksjon(const struct Brok b, const struct Brok b2) {
    struct Brok temp;
    
    temp.teller = (b.teller * b2.nevner) - (b.nevner * b2.teller);
    temp.nevner = (b.nevner * b2.nevner);
    
    return temp;
}

/**
 * Multipliserer/ganger sammen de to brøkene og returnerer svaret
 *
 *@param b - første brøken
 *@param b2 - andre brøken
 */
struct Brok multiplikasjon(const struct Brok b, struct Brok b2) {
    struct Brok temp;
    
    temp.teller = (b.teller * b2.teller);
    temp.nevner = (b.nevner * b2.nevner);
    
    return temp;
}

/**
 * Dividerer/deler to brøker med hverandre og returnerer svaret
 *
 *@param b - første brøken
 *@param b2 - andre brøken
 */
struct Brok divisjon(const struct Brok b, const struct Brok b2) {
    struct Brok temp;
    
    temp.teller = (b.teller * b2.nevner);
    temp.nevner = (b.nevner * b2.teller);
    
    return temp;
}
