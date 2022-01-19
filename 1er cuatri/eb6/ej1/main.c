#include <stdio.h>
#include <string.h>

int main ()
{
    char vector [80];
    int contador = 0;
    int minusculas = 0;
    int consonantes = 0;
    int vocales = 0;

    printf ("Ingrese una frase\n");
    fgets (vector, 81, stdin);

    printf ("La cantidad de caracteres es: %ld \n", strlen (vector));

    for (int i = 0;i < strlen(vector);i++) //i es menor a la cant de caracteres
    {
        if (vector[i] >= 'A' && vector [i] <= 'Z' )
        {
            contador ++;
        }
        else 
        {
            minusculas ++;        
        }
        
        switch (vector[i])
        {
            case 'a':
                vocales ++;
                break;
            case 'A':
                vocales ++;
                break;
            case 'e':
                vocales ++;
                break;
            case 'E':
                vocales ++;
                break;
            case 'i':
                vocales ++;
                break;
            case 'I':
                vocales ++;
                break;
            case 'o':
                vocales ++;
                break;  
            case 'O':
                vocales ++;
                break;
            case 'u':
                vocales ++;
                break;
            case 'U':
                vocales ++;
                break;
            case '\0':
                break;
            case ' ':
                break;
            default:
                consonantes ++;
        }
    }

    printf ("La cantidad de mayusculas es: %d \n",contador);
    printf ("La cantidad de minusculas es: %d \n", minusculas);
    printf ("La cantidad de consonantes es: %d \n", consonantes);
    printf ("La cantidad de vocales es: %d \n", vocales);



    //fflush(stdin);
    return 0;
}
