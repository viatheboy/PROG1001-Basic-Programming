//
//  oppg17.c
//  C_Prog
//
//  Created by Steffen Martinsen on 24/09/2022.
//

#include <stdio.h>

const int MAXLOPERE = 10;

int main (void) {
    
    int antall500;
    int distanse;
    int antallLøpere;
    int minutt;
    int sekund;
    int hundredel;
    float poeng;
    char igjen;
    
    do {
        do {
            printf("Skriv inn distanse (500, 1500, 3000, eller 5000): ");
            scanf("%i", &distanse);     getchar();
            
        } while (distanse != 500 && distanse != 1500 && distanse != 3000 && distanse != 5000); {
                antall500 = distanse/500;
                do {
                    printf("Hvor mange løpere skal det leses inn for? (Max 10) ");
                    scanf("%i", &antallLøpere);
                    
                } while (antallLøpere > MAXLOPERE);
            }
        for (int i = 0; i < antallLøpere; i++) {
            do {
                printf("Skriv inn tid for løper nr. %i: ", i+1);
                scanf("%i %i %i", &minutt, &sekund, &hundredel);
            } while (minutt < 0 || sekund <0 || hundredel <0);

            // Skriver ut tiden for løper og regner ut poengsummen
            printf("Tid for løper %i: %i:%i:%i \n", i+1, minutt, sekund, hundredel);
            poeng = ((float) minutt * 60 + (float) sekund + (float) hundredel / 100) / (float) antall500;
            printf("Poengsum for løper nr. %i: %.3f\n", i+1, poeng);
        }
        printf("Vil du kjøre programmet en gang til?\nSkriv J for JA og N for NEI:\n");
        scanf(" %c", &igjen);
    } while (igjen == 'J' || igjen == 'j');
    
    return 0;
}
