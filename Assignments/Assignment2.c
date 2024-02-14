/**
 * Oblig 2
 *  @Author. Steffen S. Martinsen
 *
 *
 *
 */

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

///< Konstantvariabler
const int STRLEN        = 40; ///< Max. tekstlengde.
const int MAXBRUKERE    = 20; ///< Max. antall brukere.
const int ASCIIFORST    = 33; ///< Første lovlige ASCII-nr som brukes.
const int ASCIISIST     = 126; ///< Siste lovlige ASCII-nr som brukes.
const int MOD = (ASCIISIST-ASCIIFORST)+1; ///< Intervallets lengde.
const int CIPHER        = 42; ///< Antall høyre-skift ved kryptering.

/**
 * Hovedprogram
 */
int main (void) {
    
    char brukerNavn[MAXBRUKERE][STRLEN]; // 2-dim array for brukernavn.
    char brukerPass[MAXBRUKERE][STRLEN]; // 2-dim array for passord.
    char midlPass[STRLEN];               // Variabel for å holde passord midlertidig.
    char brukerValg;                     // Variabel for verdien brukeren skriver inn.
    char tegn;
    
    bool litenBoks      = false; // Variabel for liten bokstav i passord.
    bool storBoks       = false; // Variabel for stor bokstav i passord.
    bool lovligeTegn    = false; // Variabel for lovlige tegn i passord.
    bool passLengde     = false; // Variabel for lovlig lengde i passord.
    
    int antBrukere      = 0; // Antall brukere registrert
    int antallTegn      = 0; // Antall tegn i passordet
    int verdi           = 0; // Variabel brukt i krypteringen
    int kryptertTegn    = 0; // Variabel brukt i krypteringen

    // Spør brukeren om input til Q er innlest
    while (brukerValg != 'Q') {
        printf("Vennligst velg et alternativ: \n");
        printf("\tN - Lag ny bruker\n");
        printf("\tL - Logg inn\n");
        printf("\tS - Skriv alle brukere\n");
        printf("\tQ - Avslutt\n");
        scanf(" %c", &brukerValg);
        brukerValg = toupper(brukerValg);
        
        // Switch som avgjør hva som gjøres basert på brukervalget
        switch (brukerValg) {
            case 'N':
                if (antBrukere >= MAXBRUKERE) {
                    printf("Kan ikke lage bruker. Antall brukere overskredet.\n");
                } else {
                    printf("Skriv inn brukernavn: ");
                    scanf(" %s", brukerNavn[antBrukere]);
                    
                    do {
                        // Nullstille variabler for hver iterasjon
                        litenBoks   = false;
                        storBoks    = false;
                        passLengde  = false;
                        lovligeTegn = false;
                        
                        printf("Skriv inn passord (Min. 3 tegn. Må inkl. stor og liten bokstav): ");
                        scanf(" %s", midlPass);
                        
                        // Sjekker om passord inneholder en stor og en liten bokstav,
                        // at alle bokstaver er lovlige, og at passordlengden er lovlig
                        for (int j = 0; j < strlen(midlPass); j++) {
                            if (midlPass[j] >= 'a' && midlPass[j] <= 'z') {
                                litenBoks = true;
                            }
                            if (midlPass[j] >= 'A' && midlPass[j] <= 'Z') {
                                storBoks = true;
                            }
                            if (midlPass[j] >= ASCIIFORST && midlPass[j] <= ASCIISIST) {
                                lovligeTegn = true;
                            }
                        }
                        
                        // If statements for å gi brukeren tilbakemelding om det som mangler
                        if (strlen(midlPass) >= 3) {
                            passLengde = true;
                        } else {
                            printf("Passord må være tre eller flere tegn.\n");
                        }
                        if (storBoks == false)
                            printf("Passordet må inneholde en stor bokstav.\n");
                        if (litenBoks == false)
                            printf("Passordet må inneholde en liten bokstav.\n");
                    } while (litenBoks == false || storBoks == false || passLengde == false || lovligeTegn == false);
                    printf("Bruker lagret\n");
                    
                    // Kryptering av passord
                    for (int i = 0; i < midlPass; i++) {
                        tegn = midlPass[i];
                        verdi = ((int)tegn - ASCIIFORST + CIPHER) % MOD;
                        kryptertTegn = (char) (verdi + ASCIIFORST);
                        midlPass[i] = kryptertTegn;
                    }
                    strcpy(brukerPass[antBrukere], midlPass);
                    printf("Krypta PW: %s\n\n", brukerPass[antBrukere]);
                    antBrukere++; // Bruker er laget og vi kan inkrementere brukervariabelen
                }
                break;
            case 'L':
                printf("Nå er vi i L\n\n");
                break;
            case 'S':
                printf("Nå er vi i S\n");
                if (antBrukere <= 0) {
                    printf("Det finnes ingen brukere å skrive ut\n");
                } else {
                    for (int i = 0; i < antBrukere; i++) {
                        printf("\t%i. Brukernavn:\t%s;\tPassord (kryptert):\t%s\n\n", i, brukerNavn[i], brukerPass[i]);
                    }
                }
                break;
            case 'Q':
                printf("Avslutter\n");
                break;
            default:
                printf("Vennligst velg en gyldig kommando\n");
                break;
        }
        
    }
    
    return 0;
}
