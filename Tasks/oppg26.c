//
//  oppg26.c
//  C_Prog
//
//  Created by Steffen Martinsen on 27/10/2022.
//

#include <stdio.h>

struct Dato {
    int dag,
        måned,
    år;
};

int main () {
    struct Dato dato;
    struct Dato dato2;
    
    printf("Den første datoen\n");
    printf("Skriv inn dagen: ");
    scanf("%i", &dato.dag); getchar();
    printf("Skriv inn måneden: ");
    scanf("%i", &dato.måned); getchar();
    printf("Skriv inn året: ");
    scanf("%i", &dato.år); getchar();

    printf("Den andre datoen\n");
    printf("Skriv inn dagen: ");
    scanf("%i", &dato2.dag); getchar();
    printf("Skriv inn måneden: ");
    scanf("%i", &dato2.måned); getchar();
    printf("Skriv inn året: ");
    scanf("%i", &dato2.år); getchar();
    
    if (dato.år > dato2.år)
        printf("%i er året som kom først.\n", dato2.år);
    else if (dato2.år > dato.år)
        printf("%i er året som kom først.\n", dato.år);
    else
        printf("Årene i datoene er like!\n");
}
