#include <stdio.h>

void ordenar_vector (char vector []);
void print_ordenado (char vector []);
void compara_vector (char vector []);

#define TAM 10

int main ()
{
    char vector [TAM];
    
    printf ("Ingrese muchas letras:\n");
    fgets (vector,TAM,stdin);

    ordenar_vector (vector);
    print_ordenado (vector);

    compara_vector (vector);

    return 0;
}

void ordenar_vector (char vector [])
{
    int i, j;
    char aux;
    
    for (j = 1;j < TAM;j++)
    {
        for (i = 0;i < (TAM - j);i++)
        {
            if (vector [i] > vector [i + 1])
            {
                aux = vector [i];
                vector [i] = vector [i + 1];
                vector [i + 1] = aux;
            }
        }
    }
}

void print_ordenado (char vector [])
{
    int i;

    printf ("Vectores en orden\n");

    for (i = 0;i < TAM; i++)
    {    
        printf ("vector[%d]: %c \n",i , vector [i]); 
    }
}

void compara_vector (char vector [])
{
    int aux = 1;
    int num;

    for (int i = 0;i < TAM;i++)
    {
        if (vector [i] >= 'a' && vector [i] <= 'z')
        {
            if (vector [i + 1] == vector [i])
            { 
                printf ("vector [%d] = %c \n", i, vector[i]);
                aux++;
                num = aux;
                if (num >= aux)
                {
                    printf ("vector [%d] = %d \n", i, num);
                }
            }
            else
            {
                aux = 1;
            }    
        }
    }
}
