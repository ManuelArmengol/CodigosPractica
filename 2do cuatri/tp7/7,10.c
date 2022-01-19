#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int year;
    int mes;
    int dia;
}fecha_t;

typedef struct nodo
{
    fecha_t date;
    struct nodo * siguiente;
}nodo_t;

void crearFecha (nodo_t ** lista, fecha_t date);
void mostrarFecha (nodo_t ** lista, fecha_t date);
void copiarFecha (nodo_t ** lista, fecha_t date);
void sigDia (nodo_t ** lista, fecha_t date);
void antDia (nodo_t ** lista, fecha_t date);


#define TAM 2

int main ()
{
    char aux = 0;
    void (*funcion[5])(nodo_t*,fecha_t);
    nodo_t * lista = NULL;
    fecha_t date;

    funcion [0] = crearFecha;
    funcion [1] = mostrarFecha;
    funcion [2] = copiarFecha;
    funcion [3] = sigDia;
    funcion [4] = antDia;

    printf ("Decida que opcion desea: \n"); 
    printf ("a) Crear fecha: \n"); 
    printf ("b) Mostrar fecha: \n"); 
    printf ("c) Copiar fecha: \n"); 
    printf ("d) Dia siguiente: \n"); 
    printf ("e) Dia anterior: \n"); 
    scanf ("%c", &aux);

    if (aux == 'a')
    {
        funcion[0](&lista,date);
    }
    else if (aux == 'b')
    {
        funcion[1](&lista,date);
    }
    else if (aux == 'c')
    {
        funcion[2](&lista,date);
    }
    else if (aux == 'd')
    {
        funcion[3](&lista,date);
    }
    else if (aux == 'e')
    {
        funcion[4](&lista,date);
    }
}

void crearFecha (nodo_t ** lista, fecha_t date)
{
    nodo_t * nuevo_elemento = (nodo_t *) malloc (sizeof (nodo_t));
    if (nuevo_elemento == NULL)
    {
        perror ("Memoria \n");
    }

    nuevo_elemento->date.year = 2020;
    nuevo_elemento->date.mes = 04;
    nuevo_elemento->date.dia = 17;

    printf ("Nueva estrcutura, fecha = %d/%d/%d\n", nuevo_elemento->date.dia,nuevo_elemento->date.mes,nuevo_elemento->date.year);

    nuevo_elemento->siguiente = NULL;

    if (*lista ==NULL)
    {
        *lista = nuevo_elemento;
    }
}

void mostrarFecha (nodo_t ** lista, fecha_t date)
{
    nodo_t * nuevo_elemento = (nodo_t *) malloc (sizeof (nodo_t));
    if (nuevo_elemento == NULL)
    {
        perror ("Memoria \n");
    }

    printf ("Ingrese un dia: \n");
    scanf ("%d", &nuevo_elemento->date.dia);

    printf ("Ingrese un mes: \n");
    scanf ("%d", &nuevo_elemento->date.mes);

    printf ("Ingrese un año: \n");
    scanf ("%d", &nuevo_elemento->date.year);

    printf ("La fecha ingresada es: %d/%d/%d \n",nuevo_elemento->date.dia,nuevo_elemento->date.mes,nuevo_elemento->date.year);

    if (*lista ==NULL)
    {
        *lista = nuevo_elemento;
    }
}

void copiarFecha (nodo_t ** lista, fecha_t date)
{
    nodo_t * nuevo_elemento = (nodo_t *) malloc (sizeof (nodo_t));
    if (nuevo_elemento == NULL)
    {
        perror ("Memoria \n");
    }

    nodo_t * nuevo_elemento2 = (nodo_t *) malloc (sizeof (nodo_t));
    if (nuevo_elemento2 == NULL)
    {
        perror ("Memoria \n");
    }

    printf ("Ingrese un dia: \n");
    scanf ("%d", &nuevo_elemento->date.dia);

    printf ("Ingrese un mes: \n");
    scanf ("%d", &nuevo_elemento->date.mes);

    printf ("Ingrese un año: \n");
    scanf ("%d", &nuevo_elemento->date.year);

    nuevo_elemento2->date.dia = nuevo_elemento->date.dia; 
    nuevo_elemento2->date.mes = nuevo_elemento->date.mes; 
    nuevo_elemento2->date.year = nuevo_elemento->date.year;

    printf ("La fecha ingresada es: %d/%d/%d \n",nuevo_elemento2->date.dia,nuevo_elemento2->date.mes,nuevo_elemento2->date.year);

    if (*lista ==NULL)
    {
        *lista = nuevo_elemento;
    }
}

void sigDia (nodo_t ** lista, fecha_t date)
{
    nodo_t * nuevo_elemento = (nodo_t *) malloc (sizeof (nodo_t));
    if (nuevo_elemento == NULL)
    {
        perror ("Memoria \n");
    }

    printf ("Ingrese un dia: \n");
    scanf ("%d", &nuevo_elemento->date.dia);

    printf ("Ingrese un mes: \n");
    scanf ("%d", &nuevo_elemento->date.mes);

    printf ("Ingrese un año: \n");
    scanf ("%d", &nuevo_elemento->date.year);   


    nuevo_elemento->date.dia = nuevo_elemento->date.dia + 1;

    printf ("Un dia despues: %d/%d/%d \n",nuevo_elemento->date.dia,nuevo_elemento->date.mes,nuevo_elemento->date.year);
}

void antDia (nodo_t ** lista, fecha_t date)
{
    nodo_t * nuevo_elemento = (nodo_t *) malloc (sizeof (nodo_t));
    if (nuevo_elemento == NULL)
    {
        perror ("Memoria \n");
    }

    printf ("Ingrese un dia: \n");
    scanf ("%d", &nuevo_elemento->date.dia);

    printf ("Ingrese un mes: \n");
    scanf ("%d", &nuevo_elemento->date.mes);

    printf ("Ingrese un año: \n");
    scanf ("%d", &nuevo_elemento->date.year);   


    nuevo_elemento->date.dia = nuevo_elemento->date.dia - 1;

    printf ("Un dia antes: %d/%d/%d \n",nuevo_elemento->date.dia,nuevo_elemento->date.mes,nuevo_elemento->date.year);
}