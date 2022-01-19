#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct tiempo
{
    int hor;
    int min;
    int seg;
    struct tiempo * siguiente;
}tiempo_t;

void crearTiempo (tiempo_t ** lista);
void mostrarTimepo (tiempo_t ** lista);

#define TAM 2

int main ()
{
    char aux = 0;
    void (*funcion[1])(tiempo_t*);
    tiempo_t * lista = NULL;

    funcion [0] = crearTiempo;
    funcion [1] = mostrarTimepo;

    printf ("Decida que opcion desea: \n"); 
    printf ("a) Crear tiempo: \n"); 
    printf ("b) Mostrar hora\n"); 
    scanf ("%c", &aux);

    if (aux == 'a')
    {
        funcion[0](&lista);
    }
    else if (aux == 'b')
    {
        funcion[1](&lista);
    }
}

void crearTiempo (tiempo_t ** lista)
{
    tiempo_t * nuevo_elemento = (tiempo_t *) malloc (sizeof (tiempo_t));
    if (nuevo_elemento == NULL)
    {
        perror ("Memoria \n");
    }

    nuevo_elemento->hor = 00;
    nuevo_elemento->min = 00;
    nuevo_elemento->seg = 00;

    printf ("Nueva estrcutura, tiempo = %d : %d : %d\n", nuevo_elemento->hor,nuevo_elemento->min,nuevo_elemento->seg);

    nuevo_elemento->siguiente = NULL;

    if (*lista ==NULL)
    {
        *lista = nuevo_elemento;
    }
}

void mostrarTimepo (tiempo_t ** lista)
{
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char output[128];
    strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);
    printf("%s\n",output);
}