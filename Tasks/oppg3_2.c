//
//  oppg3_2.c
//  GrProg
//
//  Created by Steffen Martinsen on 29/08/2022.
//

#include <stdio.h>

int main(void)  {
    int value1, value2 = 10, sum; //  3x heltallsvariable - initierer den ene.
    
    
    value1 = 20;
    
    sum = value1 + value2;

                                  //  Utskrift, der 2x inneholder "søppel":
    printf("The sum of %i and %i is %i\n", value1, value2, sum);

    sum = value1 + (value2 * 3);  //  Litt aritemetkk med/uten parenteser:
    printf("The sum of %i and %i *3 is %i\n", value1, value2, sum);

    sum = value1 + value2 * 3;
    printf("The sum of %i and %i *3 is %i\n", value1, value2, sum);

    sum = (value1 / 3) + (value2 * 3);
    printf("The sum of %i/3 and %i *3 is %i\n", value1, value2, sum);

    sum = value1 / 3 + value2 * 3;
    printf("The sum of %i/3 and %i *3 is %i\n", value1, value2, sum);

    sum = (value1 / 3 + value2) * 3;
    printf("The sum of (%i/3 and %i) *3 is %i\n", value1, value2, sum);

                          //  Konklusjon: '*' og '/' utføres fra venstre
                          //              mot høyre FØR '+' og '-' (om ikke
                          //              annet er angitt ved parentesbruk).
                          //
                          //              Heltallsdivisjon avrundes IKKE opp,
                          //              desimalene mistes/blir bare borte
                          //              (altså ingen avrunding oppover).
                          //
                          //              %d KAN brukes i stedet for %i.
                          //              I dette emnet brukes konsekvent %i.

                          //  Bruk av tabulator ('\t') og linjeskift ('\n'):
    printf("\n\nInnrykket tekst over");
    printf("flere linjer!!!!\n---\n\n");

                          //  Eller EKSAKT ALT det samme i EN setning:
    printf("\n\nInnrykket tekst over flere linjer!!!!\n---\n\n");

    return 0;
}
