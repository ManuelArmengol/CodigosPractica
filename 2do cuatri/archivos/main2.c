#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int edad_t;


typedef struct
{
    edad_t edad;
    char * nombre;
} alumnos_t;

typedef alumnos_t nodo_data_t;

typedef struct nodo
{
    nodo_data_t data;
    struct nodo * next;
} nodo_t;

void lista_push_front (nodo_t ** p_inicio, nodo_data_t dato);
void lista_push_back  (nodo_t ** p_inicio, nodo_data_t dato);
void lista_insertar   (nodo_t ** p_inicio, nodo_data_t dato, int idx);
void lista_dump       (nodo_t *  inicio, char * filename);
void lista_guardar    (nodo_t *  inicio, char * filename);
void lista_cargar     (nodo_t ** p_inicio, char * filename);
void lista_eliminar   (nodo_t ** p_inicio);

void nodo_data_cpy      (nodo_data_t * dest, nodo_data_t * orig);
void nodo_data_imprimir (nodo_data_t * data, FILE * fp);
void nodo_data_write    (nodo_data_t * data, FILE *fp);
int  nodo_data_read     (nodo_data_t * data, FILE * fp);

nodo_data_t lista_pop_front (struct nodo **p_inicio);
nodo_data_t lista_pop_back (struct nodo **p_inicio);
nodo_data_t lista_pop_mid (struct nodo **p_inicio, int idx);

int main ()
{
    nodo_t * inicio = NULL;

/*
    struct pelicula peli_nueva;

    strcpy (peli_nueva.name, "volver al futuro");
    peli_nueva.year = 2015;
    push_front (&inicio, peli_nueva);

    strcpy (peli_nueva.name, "volver al pasado");
    peli_nueva.year = 2051;
    push_front (&inicio, peli_nueva);

    strcpy (peli_nueva.name, "volver al presente");
    peli_nueva.year = 2020;

    push_back (&inicio, peli_nueva);
    nodo_data_imprimir  (inicio);
    //dump     (inicio, "lista.txt");
    guardar   (inicio, "lista.pablito");

    printf    ("Imprimo Lista\n");
    eliminar  (&inicio);
    nodo_data_imprimir  (inicio);
    printf    ("Listo, ya imprimi la Lista\n\n");

    cargar   (&inicio, "lista.pablito");
    nodo_data_imprimir (inicio);
//*/


    return 0;
}





/*******************************************************************************
 *                      NO DEPENDE DEL NODO_DATO_T
 *******************************************************************************/





void lista_push_front (nodo_t ** p_inicio, nodo_data_t dato_a_ingresar)
{
    // 1) reserva memoria
    nodo_t * nuevo_nodo = (nodo_t *) malloc (sizeof (nodo_t));

    // 2) cargar datos
    nodo_data_cpy (& nuevo_nodo->data, & dato_a_ingresar);

    // 3) re-enlazar
    nuevo_nodo->next = (*p_inicio);
    (*p_inicio) = nuevo_nodo;
}

void lista_push_back (nodo_t ** p_inicio, nodo_data_t dato_a_ingresar)
{
    nodo_t * ptr_nodo;

    // 1) alocar memoria
    nodo_t * nuevo_nodo = (nodo_t *) malloc (sizeof (nodo_t));

    // 2) cargar datos
    nodo_data_cpy (& nuevo_nodo->data, & dato_a_ingresar);

    // 3) re-enlazar
    if ((*p_inicio) == NULL)
    {
        // lista vacia
        lista_push_front (p_inicio, dato_a_ingresar);
    }
    else
    {
        // no esta vacia, la recorro hasta el final
        ptr_nodo = (*p_inicio);
        while (ptr_nodo->next != NULL)
        {
            ptr_nodo = ptr_nodo->next;
        }
    
        // en este punto estoy parado en el ultimo nodo con ptr_nodo
        // ahora si re-enlazo
        nuevo_nodo->next = ptr_nodo->next;
        ptr_nodo->next = nuevo_nodo;
    }
}

// idx = index = indice
void lista_push_mid (nodo_t ** p_inicio, nodo_data_t dato_a_ingresar, int idx)
{
    int i;
    nodo_t * ptr_nodo;

    // 1) alocar memoria
    nodo_t * nuevo_nodo = (nodo_t *) malloc (sizeof (nodo_t));

    // 2) cargar datos
    nodo_data_cpy (& nuevo_nodo->data, & dato_a_ingresar);

    // 3) re-enlazar
    if ((*p_inicio) == NULL)
    {
        // lista vacia
        lista_push_front (p_inicio, dato_a_ingresar);
    }
    else
    {
        ptr_nodo = (*p_inicio);
        for (i = 0; i < (idx-1) && ptr_nodo->next != NULL; i++) // (idx-1) porque me paro en el anterior
        {
            ptr_nodo = ptr_nodo->next;
        }

        // en este punto estoy parado en el nodo anterior a donde lo quiero
        // agregar, con ptr_nodo
        // ahora si re-enlazo
        nuevo_nodo->next = ptr_nodo->next;
        ptr_nodo->next = nuevo_nodo;
    }
}

nodo_data_t lista_pop_front (struct nodo **p_inicio)
{
    nodo_data_t copia;

    if(*p_inicio != NULL)
    {
        nodo_t *aux = *p_inicio;

        copia = (*p_inicio)->data;

        *p_inicio = (*p_inicio)->next;

        free(aux);
    }

    return copia;
}

nodo_data_t lista_pop_back (struct nodo **p_inicio)
{
    nodo_data_t copia;
    nodo_t *aux = (* p_inicio)->next;
    nodo_t *pre_aux = *p_inicio; 

    if (*p_inicio == NULL)
    {
        return copia;
    }
    else
    {	
        if (aux == NULL)
        {
            copia = lista_pop_front (p_inicio);

            return copia;
        }

        while (aux->next != NULL)
        {
            aux = aux->next; 
            pre_aux = pre_aux->next;
        }

        copia = aux->data;

        free (aux);

        pre_aux->next = NULL;
    }
    return copia;
}

nodo_data_t lista_pop_mid (struct nodo **p_inicio, int idx)
{
    struct nodo * ptr_nodo;
    nodo_data_t copia;
    
    if ((*p_inicio) == NULL)
    {
        copia = lista_pop_front (p_inicio);
        return copia;
    }
    else
    {
        ptr_nodo = (*p_inicio);
        for (int i = 0; i < (idx-1) && ptr_nodo->next != NULL; i++)
        {
            ptr_nodo = ptr_nodo->next;
        }


    }
}

void lista_guardar (nodo_t * inicio, char * filename)
{
    nodo_t * recorrer = inicio;
    FILE * fp = fopen (filename, "wb");
    
    if (fp == NULL)
    {
        perror ("Error en fopen: ");
        return;
    }

    while (recorrer != NULL)
    {
        nodo_data_write (&recorrer->data, fp);

        recorrer = recorrer -> next;
    }

    fclose (fp);
}

void lista_cargar (nodo_t ** p_inicio, char * filename)
{
    nodo_data_t dato;
    FILE * fp = fopen (filename, "rb");
    
    if (fp == NULL)
    {
        perror ("Error en fopen: ");
        return;
    }

    while (!feof (fp))
    {
        int read_bytes = nodo_data_read (&dato, fp);
        if (read_bytes > 0)
        {
            lista_push_back (p_inicio, dato);
        }
    }

    fclose (fp);
}

void lista_dump (nodo_t * inicio, char * filename)
{
    nodo_t * recorrer = inicio;
    FILE * fp = fopen (filename, "w");
    
    if (fp == NULL)
    {
        perror ("Error en fopen: ");
        return;
    }

    while (recorrer != NULL)
    {
        nodo_data_imprimir (& recorrer->data, fp);

        recorrer = recorrer -> next;
    }

    fclose (fp);
}

void lista_dump_unix (nodo_t * inicio, char * filename)
{
    nodo_t * recorrer = inicio;

    // TODO: Completar
}

void lista_eliminar (nodo_t ** p_inicio)
{
    nodo_t * aux = (*p_inicio);

    while ((*p_inicio) != NULL)
    {
        // moverme al siguiente
        (*p_inicio) = (*p_inicio) -> next;

        // Eliminar memoria dinamica de nodo_data_t

        // eliminar nodo
        free (aux);
        aux = (*p_inicio);
    }

    (*p_inicio) = NULL;
}





/*******************************************************************************
 *                      DEPENDE DEL NODO_DATO_T
 *******************************************************************************/





void nodo_data_cpy (nodo_data_t * dest, nodo_data_t * orig)
{
    dest->nombre = (char *) malloc (sizeof (char) * strlen (orig->nombre) + 1); // +1: para el '\0'
    dest->edad = orig->edad;
    strcpy (dest->nombre, orig->nombre);
}

void nodo_data_imprimir (nodo_data_t * data, FILE * fp)
{
    fprintf (fp, "nombre del alumno: %s\n", data->nombre);
    fprintf (fp, "edad del alumno: %d\n\n", data->edad);
}

void nodo_data_write (nodo_data_t * data, FILE *fp)
{
    int tam_nombre = strlen (data->nombre);
    fwrite (&tam_nombre, sizeof (int), 1, fp);
    fwrite (data->nombre, strlen(data->nombre), 1, fp);
    fwrite (data->edad, sizeof (int), 1, fp);
}

int nodo_data_read (nodo_data_t * data, FILE * fp)
{
    //printf ("bytes leidos: %d\n", read_bytes);
    int tam_nombre;
    int read_bytes = fread (&tam_nombre, sizeof (int), 1, fp); // necesito saber el tamaño de nombre antes de leer el nombre
    data->nombre = (char *) calloc (tam_nombre + 1, 1); // inicializar con 0 (calloc) para tener el '\0'
    read_bytes += fread (data->nombre, tam_nombre, 1, fp);
    read_bytes += fread (data->edad, sizeof (int), 1, fp); 

    return read_bytes;
}
