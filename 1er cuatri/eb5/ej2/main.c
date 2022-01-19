#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void load_vector (int ***vector, int tam_vector);
void radio_vector (int ***vector, int tam_vector);

int main ()
{
    int *** vector;
    int tam_vector;
    int i;
    int j;

    printf ("Ingrese un tamaño\n");
    scanf ("%d", &tam_vector);

    vector = (int ***) malloc (tam_vector *sizeof(int **));
    if (vector == NULL)
    {
        printf ("Error de memoria\n"); 
        exit (0);  
    }
    
    for (i = 0;i< tam_vector;i++)
    {   
        vector [i] = (int **) malloc (tam_vector *sizeof(int *));
        if (vector[i] == NULL)
        {
            printf ("Error de memoria\n"); 
            exit (0);  
        }
        for (j = 0;j < tam_vector;j++)
        {
            vector [i][j] = (int *) malloc (tam_vector *sizeof(int));
            if (vector [i][j] == NULL)
            {
                printf ("Error de memoria\n"); 
                exit (0);  
            }
        }
    }

    load_vector (vector, tam_vector);    

    radio_vector (vector, tam_vector);

    free (vector);
    return 0;
}

void load_vector (int ***vector, int tam_vector)
{
    int x;
    int y;
    int z;

    for (x = 0;x < tam_vector;x++)
    {
        for (y = 0; y < tam_vector;y++)
        {
            for (z = 0;z < tam_vector;z++)
            {
                printf ("Ingrese un 1 o un 0\n");
                scanf ("%d", &vector[x][y][z]);
                if (vector [x][y][z] != 1 && vector [x][y][z] != 0)
                {
                    printf ("-1\n");
                    exit (0);
                }
                printf ("vector[%d][%d][%d] = %d \n", x,y,z,vector[x][y][z]);
            }   
        }   
    }
}

void radio_vector (int ***vector, int tam_vector)
{
    float rad = 0;
    int x;
    int y;
    int z;

    for (x = 0;x < tam_vector;x++)
    {
        for (y = 0;y < tam_vector;y++)
        {
            for (z = 0;z < tam_vector;z++)
            {
                if (vector [x][y][z] == 1)
                {
                    rad = sqrt ((pow (x , 2)) + (pow (y , 2)) + (pow (z , 2)));
                    printf ("El radio es. %f \n", rad);
                }   
            }
        }   
    }

}
