#include <stdio.h>
#include <stdlib.h>

void load_vector (int **vector, int x, int y);

int main ()
{
    int ** vector;
    int x; //filas
    int y; //columnas
    int i;
    int mayor = 0;

    printf ("Ingrese cantidad de filas\n");
    scanf ("%d", &x);

    printf ("Ingrese cantidad de columnas\n");
    scanf ("%d", &y);

    vector = (int **) malloc (y * sizeof(int *));
    if (vector == NULL)
    {
        printf ("Error de memoria");
        exit (0);
    }

    for (i = 0;i < x;i++)
    {
        vector [i] = (int *) malloc (x * sizeof(int ));
        if (vector == NULL)
        {
            printf ("Error de memoria");
            exit (0);
        }
    }

    load_vector (vector, x ,y);    

    for (i = 0;i < x;i++)
    {
        for (int j = 0;j < y;j++)
        {       
            if (vector [i][j] > mayor)
            {
                mayor = vector [i][j];   
            }
        }
    }

    printf ("El numero mayor: %d \n", mayor);

    free (vector);

    return 0;
}

void load_vector (int **vector, int x, int y)
{
    int i;

    for (i = 0;i < x;i++)
    {
        for (int j = 0;j < y;j++)
        {       
            printf ("Ingrese un numero: \n");
            scanf ("%d", &vector[i][j]);
            printf ("vector[%d][%d] = %d \n", i, j, vector[i][j]);
        }
    }
}
