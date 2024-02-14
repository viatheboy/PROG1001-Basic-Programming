/**
 * Program som tar inn tre tall, kvadrerer alle sammen, sunmmerer dem, og returnerer summen av disse.
 */

#include <stdio.h>

int summerKvadrater(int tall1, int tall2, int tall3);

/**
 * Hovedprogram
 */
int main () {
    
    printf("2, 4, 6 kvadrert og lagt sammen er: %i\n", summerKvadrater(2, 4, 6));
    printf("19, 23, 92 kvadrert og lagt sammen er: %i\n", summerKvadrater(19, 23, 92));
    printf("12, 2, 21 kvadrert og lagt sammen er: %i\n", summerKvadrater(12, 2, 21));
    
}


/**
 * @param   tall1 -     Tall som skal kvadreres og summeres
 * @param   tall2 -     Tall som skal kvadreres og summeres
 * @param   tall3 -     Tall som skal kvadreres og summeres
 *
 * @return  Summen av de kvadrerte tallene.
 */
int summerKvadrater(int tall1, int tall2, int tall3) {
    
    int kvadrat1, kvadrat2, kvadrat3;
    
    // Kvadrering av de tre parameterne
    kvadrat1 = tall1 * tall1;
    kvadrat2 = tall2 * tall2;
    kvadrat3 = tall3 * tall3;
    
    return (kvadrat1 + kvadrat2 + kvadrat3);
}
