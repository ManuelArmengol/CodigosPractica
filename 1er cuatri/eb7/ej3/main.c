#include <stdio.h>
#include <string.h>
#include "ej3.h"

int main ()
{
    int vector [TAM_VECTOR];
    int num = 0;

    load_vector (vector);
    //ordenar_vector (vector);
    //print_vector (vector);

    concatenar_vector (vector);

    return 0;    
}

void load_vector (int vector [])
{
    for (int i = 0;i < TAM_VECTOR;i++)
    {
        printf ("Ingrese un numero:\n");
        scanf ("%d", &vector[i]);
    }
}

/*void ordenar_vector (int vector [])
{
    for (int j = 1;j < TAM_VECTOR;j++)
    {
        for (int i = 0;i < TAM_VECTOR - j;i++)
        {
            if (vector [i] > vector [i + 1])
            {
                aux = vector [i];
                vector [i] = vector [i + 1];
                vector [i + 1] = aux;
            }
        }
    }
}

void print_vector (int vector [])
{
    for (int i = 0;i < TAM_VECTOR;i++)
    {
        printf ("vector [%d] = %d\m", i, vector [i]);
    }
}*/
