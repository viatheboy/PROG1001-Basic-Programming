//
//  oppg19.c
//  C_Prog
//
//  Created by Steffen Martinsen on 25/09/2022.
//

#include <stdio.h>

int main (void) {
    
    int tallListe[20];
    int intervaller[5] = {0, 0, 0, 0, 0};
    
    for (int i = 0; i < 20; i++) {
        do {
            printf("Nr %i. Skriv inn et tall mellom 1 og 100: ", i+1);
            scanf("%i", &tallListe[i]);
        } while (tallListe[i] < 1 || tallListe[i] > 100);
    }

    for (int i = 0; i < 20; i++) {
        if (tallListe[i] >= 1 && tallListe[i] <= 20){
            intervaller[0]++;
        } else if (tallListe[i] > 20 && tallListe[i] <= 40) {
            intervaller[1]++;
        } else if (tallListe[i] > 40 && tallListe[i] <= 60) {
            intervaller[2]++;
        } else if (tallListe[i] > 60 && tallListe[i] <= 80) {
            intervaller[3]++;
        } else if (tallListe[i] > 80 && tallListe[i] <= 100) {
            intervaller[4]++;
        }
    }
    printf("Antall tall i intervallet  1 - 20: %i\n", intervaller[0]);
    printf("Antall tall i intervallet 21 - 40: %i\n", intervaller[1]);
    printf("Antall tall i intervallet 41 - 60: %i\n", intervaller[2]);
    printf("Antall tall i intervallet 61 - 80: %i\n", intervaller[3]);
    printf("Antall tall i intervallet 81 - 100: %i\n", intervaller[4]);
}
