#include <stdio.h>
#include "sort.h"
#include "ej3.h"

#define TAM_VECTOR 3

void load_vector (int vector [], int length);
void print_vector (int vector [], int length);

int main ()
{
    int vector [TAM_VECTOR];
    long long int max_numero;

    load_vector (vector, TAM_VECTOR);
    better_bubble_sort (vector, TAM_VECTOR, comparacion);
    print_vector (vector, TAM_VECTOR);
    max_numero = unir_vector (vector, TAM_VECTOR);

    printf ("El maximo numero posible es: %lld\n", max_numero);
}

void load_vector (int vector [], int length)
{
    for (int i = 0;i < length;i++)
    {
        printf ("Ingrese un numero: ");
        scanf ("%d", &vector[i]);
    }
}

void print_vector (int vector [], int length)
{
    if (length >= 1)
    {
        printf ("%d", vector[0]);
        for (int i = 1;i < length;i++)
        {
            printf (" - %d", vector[i]);
        }
        printf ("\n");
    }
}
