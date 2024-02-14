//
//  oppg32.c
//  C_Prog
//
//  Created by Steffen Martinsen on 03/11/2022.
//

#include <stdio.h>
#include <string.h>

const int ARRLEN = 20;

int main() {
    
    int *peker;
    int liste[ARRLEN];
    char streng[] = "ABDECDEABCCDECDA";
    char *cPeker;
    
    for (int i = 0; i < ARRLEN; i++)
        liste[i] = i+1;
    
    printf("Arrayen: \n");
    for (int i = 0; i < ARRLEN; i++) {
        if (i+1 != ARRLEN)
            printf("%i, ", liste[i]);
        else
            printf("%i.", liste[i]);
    }
    printf("\n\n");
    
    peker = liste;
    printf("Peker på arrayen: %i\n\n", *peker);
    
    for (int i = 0; i < ARRLEN; i++) {
        *(peker+i) = liste[i] * 2;
    }
    
    printf("Ganget: \n");
    for (int i = 0; i < ARRLEN; i++) {
        if (i+1 != ARRLEN)
            printf("%i, ", liste[i]);
        else
            printf("%i.", liste[i]);
    }
    printf("\n\n");
    
    /*********************************************************************************************/
    
    printf("Strengen: ");
    for (int i = 0; i < strlen(streng); i++) {
        printf("%c", streng[i]);
    }
    printf("\n\n");
    
    cPeker = streng;
    
    while (*cPeker != '\0') {
        if (*cPeker == 'C')
            *cPeker = 'X';
        else if (*cPeker == 'E')
            *cPeker = '8';
        *cPeker++;
    }
    
    
    printf("Nye strengen: ");
    for (int i = 0; i < strlen(streng); i++) {
        printf("%c", streng[i]);
    }
    
    
    return 0;
}
