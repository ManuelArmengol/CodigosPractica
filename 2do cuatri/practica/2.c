typedef struct ElementoLista
{
    int valor;
    struct ElementoLista * siguiente;
}Elemento;

typedef struct DatosLista
{
    Elemento * inicio;
    Elemento * fin;
    int tam;
}Lista;

void agregrar_nodo (Lista ** inicio)
{
    Lista  lista = (Lista *) malloc (sizeof(Lista));
    if (lista == NULL)
    {
        perror ("Error en memoria\n");
    }

    lista->inicio = NULL;
    lista->fin = NULL;
    lista->tam = 0;

    Elemento * nuevo_elemento = (Elemento *) malloc (sizeof(Elemento));
    if (nuevo_elemento == NULL)
    {
        perror ("Error en memoria\n");
    }

    if (lista->inicio == NULL)
    {
        nuevo_elemento->siguiente = lista->inicio;
        lista->inicio = nuevo_elemento;
        lista->fin = nuevo_elemento;
        lista->tam++;
    }
    else
    {
        
    }
    
}