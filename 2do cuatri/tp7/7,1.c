#include <stdio.h>

typedef struct 
{   
    int dividendo;
    int divisor;
    int cociente;
    int resto;
}division_t;

int resto (division_t dividir);
int cociente (division_t dividir);

int main ()
{
    division_t dividir;

    printf ("Ingrese el dividendo: \n");
    scanf ("%d", &dividir.dividendo);

    printf ("Ingrese el divisor: \n");
    scanf ("%d", &dividir.divisor);

    dividir.cociente = cociente (dividir);
    dividir.resto = resto (dividir);

    printf ("Cociente: %d \n", dividir.cociente);
    printf ("Resto: %d \n", dividir.resto);

    return 0;
}

int cociente (division_t dividir)
{
    int cociente = 0;

    cociente = dividir.dividendo/dividir.divisor;

    return cociente;
}

int resto (division_t dividir)
{
    int resto = 0;

    resto = dividir.dividendo % dividir.divisor;

    return resto;
}