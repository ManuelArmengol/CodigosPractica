#include <stdio.h>
#include "ej1.h"

void buscar_vector (int * vector, int n)
{
    int aux = 0;
    for (int i = 0;i < n;i++)
    {
        if (vector [i] >= 1 && vector[i] <= n)
        {
            if (vector [i] != vector[i + 1])
            {
                if (vector [i + 1] == (vector [i] + 1))
                {                    
                }
                else
                {
                    aux = vector [i] + 1;
                    printf ("Falta el nuero: %d\n", aux);
                 /*   if (aux == (vector [i + 1] + 1))
                    {
                    }
                    else
                    {
                        aux = vector [i + 1] + 1;
                        printf ("Falta el nuero: %d\n", aux);
                    }*/
                }
            }
        }
    }
}
