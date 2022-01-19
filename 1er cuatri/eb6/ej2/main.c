#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ej2.h"

void conver_puntero (char  puntero[]);

int main ()
{
    char  puntero [100];
    
    printf ("Ingrese una frase:\n");
    fgets (puntero,100,stdin);

    conver_puntero (puntero);

    string_reverse (puntero);

    return 0;
}

void conver_puntero (char  puntero[])
{
    int aux = 0;

    for (int i = 0;puntero[i] != '\0';i++)
    {
        aux = puntero[i] ;
        printf ("puntero %d = %d\n",i ,aux);
    }
}
