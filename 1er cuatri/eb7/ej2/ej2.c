#include <stdio.h>
#include "ej2.h"

void vector_largo (int vector [])
{
    int aux = 0;
    int num = 0;

    for (int i = 0;i < TAM_VECTOR;i++)
    {
        if (vector [i] == (vector [i + 1] - 1))
        {
            aux++;
            if (num <= aux)
            {
                num = aux;
            }
        }
        else
        {
            aux = 0;
        }
    }
    printf ("El tamaño es: %d \n", num + 1);
}
