#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char separa_digitos (int numero, int vector [], int tam_vector);

int main ()
{
    int numero;
    int tam_vector;
    int * vector = NULL;
    int i;

    printf ("Ingrese tamaño: \n");
    scanf ("%d", &tam_vector);
    vector = (int *) malloc(tam_vector * sizeof (int)); 

    printf ("Ingrese un numero: \n");
    scanf ("%d", &numero);

    separa_digitos (numero, vector, tam_vector);

    for (i = 0; i < tam_vector; i++)
    {
       printf ("%d", vector[i]);
    }
    printf ("\n");

    return 0;
}

char separa_digitos (int numero, int vector [], int tam_vector)
{
    int i, j;
    int cant_dig; 
    int num_aux = numero;  

    for (cant_dig = 0;num_aux / 10 != 0; cant_dig++)
    {
        num_aux /=10;
    }

    if (cant_dig > tam_vector)
    {
        return -1;
    }

    for (i = cant_dig-1, j = 0; i >= 0; i--, j++)
    {
        vector [j] = numero / pow (10, i);
        numero %=(int) pow (10, i);
    }

    return 0;
}
