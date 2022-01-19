#include <stdio.h>
#include <stdlib.h>
#include "ej7.h"

int main ()
{
    int tam_vector;
    int * vector_original;
    int * vector_ordenado;

    printf ("Ingrese un tamaño\n");
    scanf ("%d", &tam_vector);
    vector_original = (int *) malloc (tam_vector * sizeof (int));
    vector_ordenado = (int *) malloc (tam_vector * sizeof (int));

    if (vector_original == NULL || vector_ordenado == NULL)
    {
        printf ("Error al reservar mamoria\n");
    }

    printf ("Inrese: %d numeros\n", tam_vector);

    load_vector (vector_original, tam_vector);

    ordenar_vector (vector_original, tam_vector); 

    print_ordenado (vector_original, tam_vector);

    mediana (vector_original, tam_vector);

    free (vector_original);
    free (vector_ordenado);
     

    return 0;
}

void load_vector (int vector_original [],int tam_vector)
{
    int i;
    
    for (i = 0;i < tam_vector; i++)
    {
        scanf ("%d", &vector_original [i]);  
    
        printf ("vector[%d]: %d \n",i , vector_original [i]); 
    }
}
