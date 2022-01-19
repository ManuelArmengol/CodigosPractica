#include <stdio.h>
#include <stdlib.h>

#define T 30

typedef struct
{
    char patente [T];
    int motor;
    char marca [T];
    char modelo [T];
    int potencia;
    char color [T];
}auto_t;

typedef struct nodo
{
    auto_t data;
    struct nodo * siguiente;
}lista_t;

void crearLista (lista_t ** inicio);

int main ()
{
    lista_t * inicio = NULL;
    void(*funcion[7])(lista_t);

    printf ("Genere la lista de automoviles \n");
    crearLista (&inicio);
   /* orden ();
    printf ("Orden por patente: \n");
    mostrarOrden ();

    funcion [0] = modificar;
    funcion [1] = agregarAuto;
    funcion [2] = eliminarAuto;
    funcion [3] = determinarPotencia;

    printf ("Decida que opcion desea: \n"); 
    printf ("a) Modificar valores: \n");
    printf ("b) Agregar automovil: \n"); 
    printf ("c) Eliminar automovil: \n"); 
    printf ("d) Mostrar auto con mayor potencia: \n"); 

    if (aux == 'a')
    {        
        funcion [0] = modificar;
    }
    else if (aux == 'b')
    {
        funcion [1] = agregarAuto;
        orden ();
        mostrarOrden ();
    }
    else if (aux == 'c')
    {
        funcion [5] = eliminarAuto;
        orden ();
        mostrarOrden ();        
    }
    else if (aux == 'd')
    {
        funcion [6] = determinarPotencia;
    }
    else if (aux == 'd')
    {
        funcion[3](&lista,date);
    }*/

    return 0;
}

void crearLista (lista_t ** inicio)
{
    int aux = 7;

    lista_t * nuevo_elemento [aux] = (lista_t *) malloc (sizeof (lista_t)); 

    for (int i = 0;i < aux; i++)
    {
        printf ("Ingrse patente: \n");
        fflush(stdin);
        fgets (nuevo_elemento[i]->data.patente,T,stdin);

        printf ("Ingrse numero de motor: \n");
        scanf ("%d", &nuevo_elemento[i]->data.motor);

        printf ("Ingrse marca: \n");
        fflush(stdin);
        fgets (nuevo_elemento[i]->data.marca,T,stdin);

        printf ("Ingrse modelo: \n");
        fflush(stdin);
        fgets (nuevo_elemento[i]->data.modelo,T,stdin);

        printf ("Ingrse potencia: \n");
        scanf ("%d", &nuevo_elemento[i]->data.potencia);

        printf ("Ingrse color: \n");
        fflush(stdin);
        fgets (nuevo_elemento[i]->data.color,T,stdin);

        nuevo_elemento[i]->siguiente = (*inicio);
        (*inicio) = nuevo_elemento[i];    
    }
}