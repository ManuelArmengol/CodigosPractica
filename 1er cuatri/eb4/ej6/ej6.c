#include <stdio.h>
#include "ej6.h"

void ordenar_vector (int vector_original [], int tam_vector)
{
    int i, j, num;
    
    for (j = 1;j < tam_vector;j++)
    {
        for (i = 0;i < tam_vector - j;i++)
        {
            if (vector_original [i] > vector_original [i + 1])
            {
                num = vector_original [i];
                vector_original [i] = vector_original [i + 1];
                vector_original [i + 1] = num;
            }
        }
    }
}

void print_ordenado (int vector_original [], int tam_vector)
{
    int i;

    printf ("Vectores en orden\n");

    for (i = 0;i < tam_vector; i++)
    {    
        printf ("vector[%d]: %d \n",i , vector_original [i]); 
    }
}

void invertir_vector (int vector_original [], int vector_invertido [], int tam_vector)
{
    int i, j;
    int num_aux = tam_vector-1;

    printf ("Vecores en orden descendente\n");

    for (i = num_aux,j = 0;j < tam_vector;i--,j++)
    {

        vector_invertido [j] = vector_original [i];
        printf ("vector [%d] = %d \n",j ,vector_invertido [j]);
    }
}
