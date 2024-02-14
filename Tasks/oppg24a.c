/**
 * Program som tar inn en rekke verdier basert på et antall brukeren ønsker å skrive inn.
 * Programmet finner dermed den minste verdien og den høyeste verdien, basert på hvilken funksjon
 * som er tilkalt i hovedprogrammet.
 */

#include <stdio.h>

int hentMinsteVerdi(const int n);
int hentStørsteVerdi(const int n);


/**
 * Hovedprogram
 */
int main() {
    int antallTall;
    
    printf("Skriv hvor mange tall du vil lese inn: ");
    scanf(" %i", &antallTall);
    
    printf("Minste innleste tall er: %i\n", hentMinsteVerdi(antallTall));
    
    printf("Skriv hvor mange tall du vil lese inn: ");
    scanf(" %i", &antallTall);
    
    printf("Største innleste tall er: %i\n", hentStørsteVerdi(antallTall));
}

/**
 * Tar inn en rekke tall og returnerer det minste tallet.
 *
 * @param n - Antall tall som leses inn.
 *
 * @return Det minste tallet som er skrevet inn.
 */
int hentMinsteVerdi(const int n) {
    int lesInn;
    int tallListe[n];
    
    printf("Henter %i tall fra deg.\n", n);
    
    for (int i = 0; i < n; i++) {
        printf("Skriv inn tall nr. %i: ", i+1);
        scanf(" %i", &lesInn);
        
        tallListe[i] = lesInn;
    }
    int minsteTall = tallListe[0];
    
    for (int i = 0; i < n; i++) {
        
        if (tallListe[i] < minsteTall)
            minsteTall = tallListe[i];
    }
    
    return minsteTall;
}

/**
 * Funksjon som leser inn n antall tall fra brukeren og returnerer det største tallet.
 *
 * @param n - Antall tall som leses inn
 * @return Det største tallet.
 */
int hentStørsteVerdi(const int n) {
    int lesInn;
    int tallListe[n];
    int størsteTall;
    
    printf("Henter %i tall fra deg.\n", n);
    
    for (int i = 0; i < n; i++) {
        printf("Skriv inn tall nr. %i: ", i+1);
        scanf(" %i", &lesInn);
        
        tallListe[i] = lesInn;
    }
    størsteTall = tallListe[0];
    
    for (int i = 0; i < n; i++) {
        
        if (tallListe[i] > størsteTall)
            størsteTall = tallListe[i];
    }
    return størsteTall;
}
