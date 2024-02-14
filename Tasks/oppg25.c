//
//  oppg25.c
//  C_Prog
//
//  Created by Steffen Martinsen on 11/10/2022.
//

#include <stdio.h>

int     mstrlen(const char s[]);
void    mstrcpy(char s[], const char t[]);
void    mstrcat(char s[], const char t[]);

/**
 * Hovedprogram
 */
int main () {
    
    char str[100], i;
    char str2[100] = "viskr";
    char newString[100];
    
    printf("Skriv inn første string: \n");
    scanf(" %s",str);   getchar();
    printf("Lengden på strengen er: %i\n", mstrlen(str));
    
    mstrcpy(newString, str);
    
    printf("Ny string: %s\n", newString);
    
    mstrcat(str2, str);
    
    printf("%s\n", str2);
}


/**
 * Funksjon som skriver ut lengden av en string.
 *
 * @Param   s - stringen som hentes inn i hovedprogrammet.
 *
 * @return  lengden på strengden som int.
 */
int mstrlen(const char s[]) {
    
    int lengde = 0;
    for (char i = 0; s[i] != '\0'; ++i) {
        lengde++;
    }
    return lengde;
    
}

/**
 *  Funksjon som kopierer en string til en annen string.
 *
 *  @param  s - stringen som det kopieres over til.
 *  @param  t - stringen det kopieres fra.
 */
void mstrcpy(char s[], const char t[]) {
    
    int i;
    
    for (i = 0; t[i] != '\0'; ++i) {
        s[i] = t[i];
    }
    s[i] = '\0';
}

void mstrcat(char s[], const char t[]) {
    int i;
    
    for (i = 0; t[i] != '\0'; i++) {
        s[mstrlen(s)+i] = t[i];
    }
    s[i] = '\0';
}

