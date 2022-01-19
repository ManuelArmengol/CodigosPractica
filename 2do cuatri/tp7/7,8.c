#include <stdio.h>
#include <string.h>

#define TAM 5
#define T 31

struct datos
{
    long legajo;
    char apellido [T];
    char nombre [T];
};

void carga (struct datos * vector);
int fin (struct datos * vector);
void print_vector (struct datos * vector);
void minuscula (struct datos * vector);
void ordenar (struct datos * vector);
void print_ordenado (struct datos * vector);


int main ()
{
    struct datos vector[TAM];
    int aux = 0;

    carga (vector);
    aux = fin (vector);

    if (aux == 1)
    {
        printf ("Carga exitosa\n");
    }
    else
    {
        printf ("Error en el ultimo vector");
    }

    print_vector (vector);

    minuscula (vector);

    ordenar (vector);
    print_ordenado (vector);


    return 0;
}

void carga (struct datos * vector)
{
    for (int i = 0;i < TAM;i++)
    {
        printf ("Ingrese su nombre: \n");
        fflush(stdin);        
        fgets (vector[i].nombre,T,stdin);

        printf ("Ingrese su apellido: \n");
        fflush(stdin);
        fgets (vector[i].apellido,T,stdin);

        printf ("Ingrese legajo: \n");
        scanf ("%ld", &vector[i].legajo);
    }
}

int fin (struct datos * vector)
{
    for (int i = 0;i < TAM;i++)
    {
        if (vector[i].legajo == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

void print_vector (struct datos * vector)
{
    for (int i = 0;i < TAM;i++)
    {
        printf ("El nombre es: %s \n", vector[i].nombre);
        printf ("El apellido es: %s \n", vector[i].apellido);
        printf ("El legajo es: %ld \n",vector[i].legajo);
    }
}

void minuscula (struct datos * vector)
{
    for (int i = 0;i < TAM;i++)
    {
        strlwr (vector[i].apellido);
    }
}

void ordenar (struct datos * vector)
{
    struct datos aux;

    for (int i = 0;i < TAM;i++)
    {

        if (strcmp (vector[i].apellido,vector[i + 1].apellido) > 0)
        {
            
        }
    }
}

void print_ordenado (struct datos * vector)
{
    for (int i = 0;i < TAM;i++)
    {
        printf ("El vector ordenado es: \n");
        printf ("El apellido es: %s \n", vector[i].apellido);
    }
}