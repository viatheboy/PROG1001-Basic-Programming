//
//  oppg_7.c
//  GrProg
//
//  Created by Steffen Martinsen on 01/09/2022.
//

#include <stdio.h>

int main(void) {
    
    int tall1, tall2, tall3, sum, kvadratSum;
    float flyt1, flyt2, gjsnittSum, gjsnittKvadrat;
    
    tall1 = 10;
    tall2 = 25;
    tall3 = 59;
    flyt1 = 123.123;
    flyt2 = 2604.1202;
    
    sum = tall1 + tall2 + tall3;
    printf("Summen av %i + %i + %i er %i.\n", tall1, tall2, tall3, sum);
    
    gjsnittSum = sum / 3.0;
    printf("Gjennomsnittet av summen på %i er %f.\n", sum, gjsnittSum);
    
    kvadratSum = (tall1 * tall1) + (tall2 * tall2) + (tall3 * tall3);
    printf("Summen av kvadratet av %i, kvadratet av %i, og kvadratet av %i, er %i.\n", tall1, tall2, tall3, kvadratSum);
    
    gjsnittKvadrat = kvadratSum / 3.0;
    printf("Gjennomsnittet av %i er %f.\n", kvadratSum, gjsnittKvadrat);
    
    
    printf("Gjennomsnittet av %f og %f er %f.\n", flyt1, flyt2, (flyt1 + flyt2) / 2);
    
    
    return 0;
}
