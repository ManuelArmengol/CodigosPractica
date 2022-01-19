#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

#define TAM 30

typedef struct 
{
    char name [TAM];
    int games;
    int partidos;
}jugador_t;

typedef struct 
{
    jugador_t jugador1;
    jugador_t jugador2;
}partido_t;


typedef struct Lista
{
    partido_t partido;
    struct Lista * siguiente;
}lista_t;

void ingreso (lista_t ** inicio);
void ganador (lista_t * nuevo_partido, int tam);
void lista_guardar (lista_t * inicio);
void write_lista (partido_t * partido, FILE *fp);

int main ()
{
    lista_t * inicio = NULL;

    ingreso (&inicio);

    lista_guardar (inicio);

    return 0;
}

void ingreso (lista_t ** inicio)
{
    lista_t * nuevo_partido = NULL;
    int tam = 0;

    do
    {
        nuevo_partido = (lista_t *) malloc (sizeof (lista_t));
        tam++;

        printf ("Ingrese el nombre del jugador a: \n");
        __fpurge(stdin);
        scanf ("%s", nuevo_partido->partido.jugador1.name);
        __fpurge(stdin);

        printf ("Ingrese los games que gano dicho jugador: \n");
        __fpurge(stdin);
        scanf ("%d", &nuevo_partido->partido.jugador1.games);
        __fpurge(stdin);

        printf ("Ingrese el nombre del jugador b: \n");
        __fpurge(stdin);
        scanf ("%s", nuevo_partido->partido.jugador2.name);
        __fpurge(stdin);

        printf ("Ingrese los games que gano dicho jugador: \n");
        __fpurge(stdin);
        scanf ("%d", &nuevo_partido->partido.jugador2.games);
        __fpurge(stdin);

        if (nuevo_partido->partido.jugador1.games > nuevo_partido->partido.jugador2.games)
        {
            nuevo_partido->partido.jugador1.partidos ++;
        }
        else
        {
            nuevo_partido->partido.jugador2.partidos ++;
        }

        nuevo_partido->siguiente = *inicio;
        *inicio = nuevo_partido;

    }while (strcmp (nuevo_partido->partido.jugador1.name, "fin") != 0);

    ganador (nuevo_partido,tam);
}

void ganador (lista_t * nuevo_partido,int tam)
{
    lista_t aux[tam];
    while (nuevo_partido->siguiente != NULL)
    {
        if (nuevo_partido->partido.jugador1.partidos > nuevo_partido->partido.jugador2.partidos)
        {
            aux->partido.jugador1.name = nuevo_partido->partido.jugador1.name;
        }
        else
        {
            aux->partido.jugador2.name = nuevo_partido->partido.jugador2.name;
        }

        nuevo_partido = nuevo_partido->siguiente;
    }
}

void lista_guardar (lista_t * inicio)
{
    lista_t * recorrer = inicio;
    FILE * fp = fopen ("resultados.dat", "wb");
    
    if (fp == NULL)
    {
        perror ("Error en fopen: ");
        return;
    }

    while (recorrer != NULL)
    {
        write_lista (&recorrer->partido, fp);

        recorrer = recorrer -> siguiente;
    }

    fclose (fp);
}

void write_lista (partido_t * partido, FILE *fp)
{
    fwrite (partido->jugador1.name, strlen(partido->jugador1.name), 1, fp);
    fwrite (partido->jugador2.name, strlen(partido->jugador2.name), 1, fp);

    fwrite (&partido->jugador1.games, sizeof (int), 1, fp);
    fwrite (&partido->jugador2.games, sizeof (int), 1, fp);

    fwrite (&partido->jugador1.partidos, sizeof (int), 1, fp);
    fwrite (&partido->jugador2.partidos, sizeof (int), 1, fp);
}