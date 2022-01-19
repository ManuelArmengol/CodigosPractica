#include <stdio.h>
#include <stdlib.h>

void load_vector (int **vector, int tam_vector);
void matriz_vector (int **vector, int tam_vector);

#define SIMETRICA 1
#define NO_SIMETRICA 0

int main ()
{
    int **vector;
    int tam_vector;
    
    printf ("Ingrese un unico valor para filas y columnas\n");
    scanf ("%d", &tam_vector);

    vector = (int **) malloc (tam_vector * sizeof(int *));
    if (vector == NULL)
    {
        printf ("Error al reservar memoria\n");
    }    
    for (int i = 0;i < tam_vector;i++)
    {
        vector [i] = (int *) malloc (tam_vector * sizeof(int));
        if (vector [i] == NULL)
        {
            printf ("Error al reservar memoria\n");   
        }    
    } 
    
    load_vector (vector, tam_vector);

    matriz_vector (vector, tam_vector);

    free (vector);
    return 0;
}

void load_vector (int **vector, int tam_vector)
{
    for (int i = 0;i < tam_vector;i++)
    {
        for (int j = 0;j < tam_vector;j++)
        {
            printf ("Ingrese un numero\n");
            scanf ("%d", &vector[i][j]);
            printf ("Vector[%d][%d] = %d\n", i , j, vector[i][j]);   
        }
    }
}

void matriz_vector (int **vector, int tam_vector)
{
    int variable;

    for (int i = 0;i < tam_vector;i++ )
    {   
        for (int j = 0;j < tam_vector;j++)
        {
            if (i != j )
            {
                if (vector [i][j] == vector [j][i])
                {
                    variable = SIMETRICA;
                }
                else
                {
                    variable = NO_SIMETRICA;
                }
            }
        }
    } 
    printf ("La matriz es: %d \n", variable);
}
