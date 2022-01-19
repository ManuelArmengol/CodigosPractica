#include <stdio.h>
#include "ej2.h"


int main ()
{
    float vector [100];
    float promedio;
    int tam_vector;

    printf ("Ingrese un numero menor o igual a 100\n");
    scanf ("%d", &tam_vector);
    if (tam_vector >100)
    {
        printf ( "Error, ingrese otro numero \n");
        scanf ("%d", &tam_vector);
    }
   
    promedio = calcula_promedio (vector, tam_vector);
    printf ("El promedio del vector es %f \n", promedio);


    return 0;
}
