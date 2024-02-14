//
//  oppg9.c
//  GrProg
//
//  Created by Steffen Martinsen on 02/09/2022.
//

#include <stdio.h>

int main (void) {
    
    int totalSekunder, timer, minutter, sekunder;
    
    totalSekunder = 312304;
    
    minutter = totalSekunder / 60;
    timer = minutter / 60;
    sekunder = totalSekunder % 60;
    minutter %= 60;
    
    printf("%i sekunder tilsvarer %i time(r), %i minutt(er) og %i sekund(er).\n", totalSekunder, timer, minutter, sekunder);
    
    return 0;
    
}
