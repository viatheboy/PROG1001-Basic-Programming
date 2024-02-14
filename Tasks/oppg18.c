//
//  oppg18.c
//  C_Prog
//
//  Created by Steffen Martinsen on 25/09/2022.
//

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    
    for (int i = 0; i < 100; i++) {
        printf("%i ", i + 1);
        if (i % 2 == 0) {
        printf("(Partall)\n");
        } else
        printf("(Oddetall)\n");
    }
    
    return 0;
}
