#include <stdio.h>

typedef struct 
{
    int formato;
    int am;
    int fm;
}horario_t;

int main ()
{
    horario_t hora;

    printf ("Ingrese una hora en formato 24hs: \n");
    scanf ("%d", &hora.formato);

    if (hora.formato > 12 && hora.formato <25)
    {
        hora.fm = hora.formato - 12;
        printf ("%d pm \n", hora.fm);
    }else if (hora.formato <12 || hora.formato == 12)
    {
        hora.am = hora.formato;
        printf ("%d am \n", hora.am);
    }
    else
    {
        printf ("Error \n");      
    }

    return 0;
}

