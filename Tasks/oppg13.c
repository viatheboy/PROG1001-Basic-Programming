/**
 Program som skriver ut sammenhengen mellom radie og volum for en sylinder.
 */

#include <stdio.h>

const int SYLINDERHØYDE = 4;
const int PI = 3.14;


/// Hovedprogram
int main(void) {
    
    int radie;
    
    printf("Skriv inn et tall mellom 5 og 20: ");
    scanf("%i", &radie);
    
    for (int i = 1; i <= radie; i++) {
        printf("Når tallet er %i, er sammenhengen mellom radie og volum: %i\n", i,  i * i * PI * SYLINDERHØYDE);
    }
    
}
