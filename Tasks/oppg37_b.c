/*
Filen ‘METROLOG.DTA’ har følgende format for post (fire felter på en linje): <dagnr> <min.temp> <max.temp> <nedbør>
Skriv et program som leser disse dataene inn fra filen. 
Programmet beregner så og skrive ut på skjermen: gjennomsnittlig minimumstemperatur, maksimumstemperatur og nedbør.
Filen består bare av heltall, men klarer du å få til at utskriften er flyttall med en desimal?
*/

#include <stdio.h>

const int ARRLENGDE = 11;

int main () {

    // Variabler for å holde de ulike verdiene
    int dagnr[ARRLENGDE]; 
    int minTemp[ARRLENGDE];
    int maxTemp[ARRLENGDE]; 
    int nedbør[ARRLENGDE];

    // Variabler for utregning
    int totalMinTemp = 0;
    int totalMaxTemp = 0;
    int totalNedbør = 0;
    float gjMinTemp;
    float gjMaxTemp;
    float gjNedbør;

    FILE* innfil;

    innfil = fopen("METROLOG.txt", "r");        // Åpner filen for innlesning.

    // If statement for å sjekke om filen eksisterer. Leser så inn dataen ARRLENGDE antall ganger.
    if (innfil) {
        for (int i = 0; i < ARRLENGDE; i++) {
            fscanf(innfil, "%i %i %i %i", &dagnr[i], &minTemp[i], &maxTemp[i], &nedbør[i]);
            getc(innfil);
        }
    } else {
        printf("Klarte ikke finne filen.\n");
    }

    fclose(innfil);             // Lukker filen.
    
    // Skriver ut innholdet som er innlest.
    for (int i = 0; i < ARRLENGDE; i++) {
        printf("dagNr: %i \tminTemp: %i \tmaxTemp: %i \tNedbør: %i\n", dagnr[i], minTemp[i], maxTemp[i], nedbør[i]);
    }
    printf("\n\n");

    // Legger sammen all data i temperatur og nedbør, regner deretter ut gjennomsnittet av alle tre. 
    for (int i = 0; i < ARRLENGDE; i++) {
        totalMinTemp += minTemp[i];
        totalMaxTemp += maxTemp[i];
        totalNedbør += nedbør[i];
    }

    gjMinTemp = (float) totalMinTemp / ARRLENGDE;
    gjMaxTemp = (float) totalMaxTemp / ARRLENGDE;
    gjNedbør = (float) totalNedbør / ARRLENGDE;

    printf("Gjennomsnitts Minimum Temperatur: \t%.1f\nGjennomsnitts Maksimum Temperatur: \t%.1f\nGjennomsnittsnedbør: \t\t\t%.1f\n", gjMinTemp, gjMaxTemp, gjNedbør);

    return 0;
}