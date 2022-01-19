#include <stdio.h>
#include <stdlib.h>

typedef union
{
   long numero;
   char recorrer[8];
}union_t;

#define TAM 8

int main ()
{
    union_t ejemplo;

    printf ("Ingrese un numero: \n");
    scanf ("%ld", &ejemplo.numero);

    for (int i = 0;i < 8;i++)
    {
        ejemplo.recorrer[i] = ejemplo.numero;
        printf ("byte %d: %d \n", i, ejemplo.recorrer[i]);
    }
}