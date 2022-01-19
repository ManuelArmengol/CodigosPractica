#include <stdio.h>
#include <stdlib.h>
#include "ej1.h"

void load_vector (int * vector, int n);
void ordenar_vector (int * vector, int n);
void print_ordenado (int * vector, int n);

int main ()
{
    int * vector;
    int n;

    printf ("Ingrese un valor para el vector\n");
    scanf ("%d", &n);
    vector = (int *) malloc(n * sizeof (int));
    if (vector == NULL)
    {
        printf ("Error\n");
        exit (0);
    }

    load_vector (vector, n);
    ordenar_vector (vector, n);
    print_ordenado (vector, n);

    buscar_vector (vector, n);

    free (vector);
    return 0;
}

void load_vector (int * vector, int n)
{
    for (int i = 0;i < n;i++)
    {
        printf ("Ingrese un numero: \n");
        scanf ("%d", &vector[i]);
    }
}

void ordenar_vector (int * vector, int n)
{
    int aux;

    for (int j = 1;j < n;j++)
    {
        for (int i = 0;i < n - j;i++)
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

void print_ordenado (int * vector, int n)
{
    int i;

    printf ("Vectores en orden\n");

    for (i = 0;i < n; i++)
    {    
        printf ("vector[%d]: %d \n",i , vector [i]); 
    }
}
