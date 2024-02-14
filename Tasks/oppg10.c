//
//  oppg10.c
//  GrProg
//
//  Created by Steffen Martinsen on 02/09/2022.
//

#include <stdio.h>

int main (void) {
    
    int nyChar1, nyChar2;
    char tegn1 = 'F', tegn2 = 'H';
    float flyt1 = 17.52, flyt2 = 451.87;
    
    printf("Flyt2: %f, flyt1: %f, tegn2 = %c, tegn1 = %c\n", flyt2, flyt1, tegn2, tegn1);
    printf("\nFly2 på eksponentiell form: %e\n\n", flyt2);
    
    printf("Flyt1 og flyt2 som heltall: %i og %i\n\n", (int) flyt1, (int) flyt2);
    
    nyChar1 = (int) tegn1;
    printf("Tegn1 som en int: %i\n\n", nyChar1);
    
    nyChar2 = (int) 'b';
    printf("b castet om til en integer: %i\n\n", nyChar2);
    
    return 0;
    
}

