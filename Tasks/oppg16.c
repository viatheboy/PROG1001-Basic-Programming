/**
 * Multidimensjonal Array
 * Loops
 *
 * Ctype header fil.
 */


#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

const int MINVERDI = 1; ///< Minimum verdi brukt i programmet
const int MAXVERDI = 1000; ///< Max verdi brukt i programmet

/**
 * Hovedprogram
 */
int main(void) {
    
    int enDim[5];
    int taInn;
    char flerDim[10];
    char charInn;
    
    // Leser inn tall mellom 1 og 1000
    // Tall utenfor disse verdiene forkastes
    for (int i = 0; i < 5; i++) {
        do {
            printf("Skriv inn et heltall mellom 1 og 1000: ");
            scanf("%i", &taInn);
        } while (taInn < MINVERDI || taInn > MAXVERDI); {
            enDim[i] = taInn;
            printf("Registrert tall er: %i\n", enDim[i]);
        }
    }
    
    // Skriver ut alle tallene i arrayen en etter en
    for (int i = 0; i < 5; i++) {
        printf("Tall nr. %i er: %i\n", i+1, enDim[i]);
    }
    
    // Leser inn 10 bokstaver en etter en. Sjekker om disse er bokstaver
    for (int i = 0; i < 10; i++) {
        printf("Skriv inn en bokstav (ikke Æ, Ø, Å): ");
        scanf(" %c", &charInn);
        flerDim[i] = toupper(charInn);
        printf("Registrert bokstav er: %c\n", flerDim[i]);
    } while (isalpha(charInn) == false);
    
    // Skriver ut alle ordene som en setning
    printf("Innleste ord er: ");
    for (int i = 0; i < 10; i++) {
        printf("%c", flerDim[i]);
    }
    
    printf("\n");
    return 0;
}
