#include <stdio.h>
#include "ej3.h"

void concatenar_vector (int vector [])
{      
    int num, num2, u, d, c; //numero/unidades/decenas/centenas
    int dig_mayor;

    for (int i = 0;i < TAM_VECTOR;i++)
    {
        u = vector [i] % 10;

        num = vector [i] - u;
        num = num % 100;
        d = num / 10;

        num2 = vector[i] - (d*10) - u;
        c = num2 / 100;

        if (u >= d && u >= c)
        {
            dig_mayor = u;
        }
        else if (d >= u && d >=c)
        {
            dig_mayor = d;
        }
        else if (c >= u && c >= d)
        {
            dig_mayor = c;
        } 
    }

    void (*funcion)(int);
    funciom = &compara_vector;
    funcion (ptr);


}

void compara_vector (int vector [], int dig_mayor)
{
    int  ptr[TAM_VECTOR];
    int aux;

    for (int i = 0;i < TAM_VCTOR;i++)
    {
        ptr[i] = &vector[i];
        *ptr[i] = dig_mayor; 
    }

    for (int j = 1;j < TAM_VECTOR;j++)
    {
        for (int i = 0;i < TAM_VECTOR - j;i++)
        {
            if (ptr [i] < ptr [i + 1])
            {
                aux = ptr [i];
                ptr [i] = ptr [i + 1];
                ptr [i + 1] = aux;
            }
        }
    }
}



}
