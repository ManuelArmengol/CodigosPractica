#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main ()
{ 
    char  puntero[100];
    char puntero2[100];

    printf ("Ingrese una frase:\n");
    fgets (puntero,100,stdin);
    printf ("Ingrese otra frase:\n");
    fgets (puntero2,100,stdin);

    for (int i = 0;puntero [i] != '\0';i++)
    {
        printf ("puntero %d con toupper: %c \n", i, toupper(puntero [i])); 
    }  

    for (int i = 0;puntero [i] != '\0';i++)
    {
        printf ("puntero %d con tolower: %c \n", i, tolower(puntero [i]));  
    }  

    printf ("puntero con strlen: %ld \n", strlen(puntero)); 
 
    if (puntero != puntero2)
    {
        printf ("puntero con strcpy: %s \n",strcpy(puntero,
                                                            puntero2));
    }
    printf ("puntero con strcat: %s \n", strcat(puntero, puntero2));

    if (strcmp(puntero, puntero2) == 0)
    {
        printf ("puntero con strcmp: verdadero \n");
    }
    else
    {
        printf ("puntero con strcmp: falso \n");
    }

    return 0;
}
