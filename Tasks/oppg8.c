//
//  oppg_8.c
//  GrProg
//
//  Created by Steffen Martinsen on 01/09/2022.
//

#include <stdio.h>

const int ANTALL = 17;


int main(void) {
    
    int tall1, tall2, tall3, svar;
    
    tall1 = 13;
    tall2 = 100;
    tall3 = 195;
    
    
    // Bruk av tradisjonelle aritmetiske operasjoner og legger resultatet inn i svar
    svar = tall2 * ANTALL / tall1;
    printf("%i ganger %i delt på %i er %i.\n", tall2, ANTALL, tall1, svar);

    svar = tall3 + tall2 + ANTALL;
    printf("%i + %i + %i = %i\n", tall3, tall2, ANTALL, svar);

    svar = ANTALL * tall1 + tall3;
    printf("%i ganger med %i, pluss %i, er lik %i\n", ANTALL, tall1, tall3, svar);

    svar = tall3 - tall2 - ANTALL;
    printf("%i - %i - %i = %i\n", tall3, tall2, ANTALL, svar);
    
    
    // Bruk av snarvei aritmetiske operasjoner
    svar = 0;
    svar += tall1 + ANTALL * tall1;
    printf("\n\n%i + %i * %i = %i\n", tall1, ANTALL, tall1, svar);

    svar /= 4;
    printf("234 / 4 = %i\n", svar);
    
    svar += tall1 * ANTALL;
    printf("50 + %i * %i = %i\n", tall1, ANTALL, svar);
    
    svar -= tall3;
    printf("279 - %i = %i\n\n\n", tall3, svar);
    
    
    // Øke tall med increment operatoren
    printf("%i økt med en er %i\n", tall1, ++tall1);
    printf("%i økt med en er %i\n", tall1, ++tall1);
    printf("%i økt med en er %i\n", tall1, ++tall1);

    
    // Redusere tall med decrement operatoren
    printf("\n\n%i redusert med en er %i\n", tall2, --tall2);
    printf("%i redusert med en er %i\n", tall2, --tall2);
    printf("%i redusert med en er %i\n", tall2, --tall2);
    printf("%i redusert med en er %i\n\n", tall2, --tall2);
    
    // Produktet av disse trukket fra ANTALL
    printf("Produktet av disse tallene trukket fra %i er %i\n", ANTALL, tall1 * tall2 - ANTALL);
    
    return 0;
    
}
