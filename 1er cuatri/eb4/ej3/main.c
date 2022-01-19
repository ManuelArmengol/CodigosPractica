#include <stdio.h>
#include "ej3.h"

int main ()
{
    float radios [20];
    int cantidad_de_disparos = 20;
    int puntaje;
    
    puntaje = calcula_puntaje (radios, cantidad_de_disparos);

    printf ("El puntaje es: %d \n", puntaje);


    return 0;
}

