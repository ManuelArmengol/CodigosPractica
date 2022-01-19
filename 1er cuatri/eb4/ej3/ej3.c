#include "ej3.h"

int calcula_puntaje (float radios [], int cantidad_de_disparos)
{
    int i;
    int puntaje = 0;

    for (i = 0; i < cantidad_de_disparos; i++)
    {
        if (radios [i] < 0)
        {
            printf ("ERROR\n");
            break;
        }

        if (radios [i] >= 0 && radios <= RADIO_1)
        {
            puntaje += CENTRO;
            printf ("10\n");
        }
        else if (radios [i] <= RADIO_2)
        {
            puntaje += MEDIO;
            printf ("5\n");
        }
        else if (radios [i] <= RADIO_3)
        {
            puntaje += EXTREMO;
            printf ("1\n");
        }
        else 
        {
            puntaje += FALLA;
            printf ("0\n");
        }
    }

    return puntaje;
}
