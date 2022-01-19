#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ej2.h"

void string_reverse (char puntero[])
{
    int j = strlen (puntero) - 1;
    for (int i = 0;puntero[i] != '\0';i++,j--)
    {
        printf ("puntero %d = %d \n", j , puntero[i]);
    }
}
