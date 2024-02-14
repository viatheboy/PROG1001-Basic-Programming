/** Oppgave 16
 * Program som leser inn tall i en int array på fem. 
 * */

#include <stdio.h>

const int MINVERDI = 1; ///< Variabel som definerer minimum verdi
const int MAXVERDI = 1000; ///< Variabel som definerer maximum verdi

///< Hovedprogram
int main(void) {

    int enDim[5];
    int taInn;
    char multiDim2;

    // Leser inn tall mellom 1 og 1000
    // Forkaster tallet om det ikke er innenfor disse verdiene
    for (int i = 0; i < 5; i++) {
        do {
        printf("Skriv inn tall mellom 1 og 1000: ");
        scanf("%i", &taInn);
        } while (taInn < 1 || taInn > 1000); {
            enDim[i] = taInn;
            printf("Da er multiDim[%i]: %i\n", i, enDim[i]);
        }
    }
    for (int i = 0; i < 5; i++) {
        printf("Tall nr. %i = %i\n", i+1, enDim[i]);
    }

    return 0;
}