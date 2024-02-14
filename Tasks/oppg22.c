//
//  oppg22.c
//  C_Prog
//
//  Created by Steffen Martinsen on 05/10/2022.
//

#include <stdio.h>

void lagFirkant(int bredde, int høyde);

int main (void) {
    
    lagFirkant(10, 6);
    
    return 0;
}


void lagFirkant(int bredde, int høyde) {
    
    int j = 0;
    int k = 0;
    int l = 0;
    
    for (int i = 0; i < bredde; i++) {
        printf("*");
    }
    
    for (int j = 0; j < høyde-2; j++) {
        printf("\n*");
        
        while (k < bredde-2) {
            printf(" ");
            k++;
        }
        
        printf("*");
    }

    for (int i = 0; i < bredde; i++) {
        printf("*");
    }

}
