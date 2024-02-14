//
//  oppg5.c
//  GrProg
//
//  Created by Steffen Martinsen on 29/08/2022.
//

#include <stdio.h>

int main(void){
    
    /* Kode for å regne ut volume til en prisme
    */
    
    // Definering av variablene
    int lengde, bredde, høyde, volum;
    
    // Inisialisering av lengde, bredde, høyde
    lengde = 8;
    bredde = 12;
    høyde = 16;
    
    // Regne ut volumet ved lbh
    volum = lengde * bredde * høyde;
    
    // Skrive ut verdiene av prismet og volumet dens
    printf("Om vi har en rettvinklet prisme med: \n");
    printf("Lengde: \t\t%i\n", lengde);
    printf("Bredde: \t\t%i\n", bredde);
    printf("Høyde:  \t\t%i\n", høyde);
    printf("Er volumet = \t%i\n\n", volum);
    
    /* Kode for å å skrive ut 1960 */
    
    // Definering av variablene
    int tallet, årstallet, tallet2;
    
    // Inisialisering av tallet vi trenger
    tallet = 19600406;
    
    // Regne ut årstallet
    tallet2 = tallet - 1960;
    årstallet = tallet - tallet2;
    
    printf("Vi startet med %i, \nderetter fikk vi %i, \nog vi endte opp med året %i.\n", tallet, tallet2, årstallet);
    
    return 0;
}
