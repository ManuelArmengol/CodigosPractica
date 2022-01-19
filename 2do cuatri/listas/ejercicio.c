#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	char * nombre;
	int periodo;
	struct pelicula_t * siguiente;
}pelicula_t;

typedef struct
{
	pelicula_t * inicio;
	pelicula_t * fin;
	int tam;
}lista_t;


void inicializacion (lista_t *lista);
void cargar_lista (pelicula_t * pelicula, lista_t * lista);

int main ()
{
	cargar_lista;
	return 0;
}

void inicializacion (lista_t *lista)
{
	lista->inicio = NULL;
	lista->fin = NULL;
	lista->tam = 0;
}

void cargar_lista (pelicula_t * pelicula, lista_t * lista)
{
	pelicula_t * nueva_pelicula;
	nueva_pelicula = (pelicula_t *) malloc (sizeof(pelicula_t));
	if (nueva_pelicula == NULL)
	{
		exit (0);
	}

	char string [100];

	printf ("Ingrese el nombre de la pelicula: \n");
	scanf ("%hhd", string);
	nueva_pelicula->nombre = (pelicula_t *) malloc ((strlen(string)+1) * sizeof (pelicula_t));
	if (pelicula->nombre == NULL)
	{
		exit (0);
	}
	strcpy (pelicula->nombre, string);

	printf ("Ingrese el año: \n");
	scanf ("%d", pelicula->periodo);

	nueva_pelicula->siguiente = NULL;
	lista->inicio = nuevo_elemento;
 	lista->fin = nueva_pelicula;
	lista->tam++; 
}

