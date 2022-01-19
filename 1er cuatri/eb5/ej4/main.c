#include <stdio.h>
#include <stdlib.h>
#include "suma.h"

void load_vector (int ** vector, int tam_vector);

int main ()
{
    int ** vector;
    int tam_vector;

    printf ("Ingrese un tamaño para filas y columnas\n");
    scanf ("%d", &tam_vector);
    
    vector = (int **) malloc (tam_vector * sizeof(int *));
    if (vector == NULL)
    {
        printf ("Error al reservar memoria\n");
    }
    for (int i = 0;i < tam_vector;i++)
    {
        vector [i] = (int *) malloc (tam_vector * sizeof(int));
        if (vector[i] == NULL)
        {
            printf ("Error al reservar memoria\n");
        }
    }

    load_vector (vector, tam_vector);

    matriz_vector (vector, tam_vector);

    free (vector);
    return 0;
}

void load_vector (int ** vector, int tam_vector)
{
    for (int i = 0;i < tam_vector;i++)
    {
        for (int j = 0;j < tam_vector;j++)
        {
            printf ("Ingrese numero\n");
            scanf ("%d", &vector [i][j]);
            printf ("vector [%d][%d] = %d\n", i, j , vector[i][j]);
        }
    }
}


