#include <stdio.h>
#include <stdlib.h>

void invertir_vector (int vector_original [], int vector_invertido [], int tam_vector);
void load_vector (int vector_original [], int tam_vector);

int main ()
{
    int * vector_original;
    int * vector_invertido;
    int tam_vector;

    printf ("Ingrese un tamaño: \n");
    scanf ("%d", &tam_vector);

    vector_original = (int *) malloc (tam_vector * sizeof (int));
    vector_invertido = (int *) malloc (tam_vector * sizeof (int));

    load_vector (vector_original, tam_vector);

    invertir_vector (vector_original, vector_invertido, tam_vector);

    return 0;
}

void load_vector (int vector_original [], int tam_vector)
{
    int i;
    
    for (i = 0;i < tam_vector;i++)
    {   
        printf ("Ingrese un numero\n");
        scanf ("%d", &vector_original [i]);
        printf ("vector[%d]: %d \n",i , vector_original [i]); 
    }
}

void invertir_vector (int vector_original [], int vector_invertido [], int tam_vector)
{
    int i = 0;

    
}
