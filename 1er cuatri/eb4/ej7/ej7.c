#include <stdio.h>
#include "ej7.h"

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

void mediana (int vector_original [], int tam_vector)
{
    int j;
    float med;

    if ((tam_vector % 2) == 0 )
    {   
        for (j = 0;j < (tam_vector/2);j++)
        {
            med = (vector_original [j] + vector_original [j + 1]);
            med = med / 2;
        }
    }
    else
    {
        for (j = 0;j < (tam_vector/2);j++)
        {
            med = vector_original [j + 1];
        }        
    }
    printf ("La mediana es: %f \n",med);
}
