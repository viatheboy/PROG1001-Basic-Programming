/**
 * Obligatorisk oppgave 1
 * GRPROG H2022
 
 * Program som tar inn brukerinformasjon om navn, timelønn, og ferieuker
 * om to personer. Bruker denne informasjonen til å finne lengde på navnet,
 * ukeslønn, månedslønn, og årslønn.
 * Alt dette skrives ut.
 * I tillegg avklares det om brukerne har likt navn eller lik timelønn.
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/// Definering av konstantvariabler brukt i aritmetiske operasjoner, og lengde på string-array
const int DAGSTIMER   = 8; ///< Variabel som representerer antall arbeidstimer i en dag
const int ARBEIDUKER  = 5; ///< Variabel som representerer antall arbeidsdager i en uke
const float UKERMÅNED = 4.33; ///< Variabel som beskriver antall uker i en måned
const int UKERÅR      = 52; ///< Variabel som beskriver antall uker i et år
const int STRLEN      = 15; ///< Variabel som beskriver lengden i string-arrays

/// Hovedprogram
int main(void) {
    
    /* Definering av variabler for innskrivning av brukerinformasjon,
     *  utregning av lønn, og avklaring om navn og lønn er like
     */
    char navn1[STRLEN];
    char navn2[STRLEN];
    int  timelønn1;
    int  timelønn2;
    int  ferieuker1;
    int  ferieuker2;
    
    int  dagslønn;
    int  ukelønn;
    int  månedslønn;
    int  årslønn;
    int  ferietrekk;
    
    bool liktNavn;
    bool likLønn;
    
    // Innlesning av verdiene til begge personene
    printf("Skriv inn navn på første person: ");
    scanf("%s", navn1);
    printf("Skriv inn navn på andre person: ");
    scanf("%s", navn2);
    printf("Skriv inn timelønnen til %s: ", navn1);
    scanf("%i", &timelønn1);
    printf("Skriv inn timelønnen til %s: ", navn2);
    scanf("%i", &timelønn2);
    printf("Skriv inn antall ferieruker til %s: ", navn1);
    scanf("%i", &ferieuker1);
    printf("Skriv inn antall ferieuker til %s: ", navn2);
    scanf("%i", &ferieuker2);
    
    // Utregning av lønn for person 1
    dagslønn    = timelønn1 * DAGSTIMER;
    ukelønn     = dagslønn * ARBEIDUKER;
    månedslønn  = ukelønn * UKERMÅNED;
    ferietrekk  = ferieuker1 * ukelønn;
    årslønn     = (ukelønn * UKERÅR) - ferietrekk;
    
    // Utskrift for person 1
    printf("\nNavn: \t\t%s\t(lengde: %i)\n", navn1, strlen(navn1));
    printf("Timelønn: \t%i\n", timelønn1);
    printf("Ferieuker: \t%i\n", ferieuker1);
    printf("Ukelønn: \t%i\n", ukelønn);
    printf("Månedslønn: %i\n", månedslønn);
    printf("Årslønn: \t%i\n", årslønn);
    
    // Utregning av lønn for person 2 - gjenbruk av variabler
    dagslønn    = timelønn2 * DAGSTIMER;
    ukelønn     = dagslønn * ARBEIDUKER;
    månedslønn  = ukelønn * UKERMÅNED;
    ferietrekk  = ferieuker2 * ukelønn;
    årslønn     = (ukelønn * UKERÅR) - ferietrekk;
    
    // Utskrift for person 2
    printf("\nNavn: \t\t%s\t(lengde: %i)\n", navn2, strlen(navn2));
    printf("Timelønn: \t%i\n", timelønn2);
    printf("Ferieuker: \t%i\n", ferieuker2);
    printf("Ukelønn: \t%i\n", ukelønn);
    printf("Månedslønn: %i\n", månedslønn);
    printf("Årslønn: \t%i\n", årslønn);
    
    // Avklare om navn og timelønn er likt
    liktNavn = !strcmp(navn1, navn2);
    likLønn = timelønn1 == timelønn2;
    
    printf("\nLike navn: %i\n", liktNavn);
    printf("Lik timelønn: %i\n", likLønn);
    
    return 0;
}
