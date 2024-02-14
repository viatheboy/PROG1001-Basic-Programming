//
//  oppg34.c
//  C_Prog
//
//  Created by Steffen Martinsen on 08/11/2022.
//

#include <stdio.h>
#include <string.h>

void finnTegn(const char* t, char* f, char* m, char* s);

int main() {
    
    char tekst[40] = "Horeunge";
    char f = 'i';
    char m = 'G';
    char s = 'W';
    
    printf("f = %c, m = %c, s = %c\n", f, m , s);
    
    finnTegn(tekst, &f, &m, &s);
    
    printf("f = %c, m = %c, s = %c\n", f, m , s);
}

void finnTegn(const char* t, char* f, char* m, char* s) {
    int lengde = strlen(t);
    
    *f = *t;
    *m = *(t+(lengde/2)-1);
    *s = *((t+lengde)-1);
}
