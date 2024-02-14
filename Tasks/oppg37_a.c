/*
Filen ‘METROLOG.DTA’ har følgende format for post (fire felter på en linje): <dagnr> <min.temp> <max.temp> <nedbør>
Skriv et program som leser disse dataene inn fra filen. 
Programmet beregner så og skrive ut på skjermen: gjennomsnittlig minimumstemperatur, maksimumstemperatur og nedbør.
Filen består bare av heltall, men klarer du å få til at utskriften er flyttall med en desimal?
*/

#include <stdio.h>

int main () {

    int dagnr, minTemp, maxTemp, nedbør;

    FILE* innfil;

    innfil = fopen("METROLOG.txt", "r");

    if (innfil) {
        fscanf(innfil, "%i %i %i %i", &dagnr, &minTemp, &maxTemp, &nedbør);
        getc(innfil);
    } else {
        printf("Klarte ikke finne filen.\n");
    }

    fclose(innfil);

    printf("dagNr: %i, minTemp: %i, maxTemp: %i, Nedbør: %i\n", dagnr, minTemp, maxTemp, nedbør);

    return 0;
}