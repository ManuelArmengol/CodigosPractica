#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replace (char *s, char nuevo, char viejo);


int main ()
{
    char s [50];
    char nuevo = 'x';
    char viejo = 'o';

    printf ("Ingrese una frase, si tiene la letra o la misma sera reemplazada:\n");
    fgets (s,50,stdin);

    replace (s,nuevo,viejo);
    printf ("La frase remplazada es: %s",s);

    return 0;
}

void replace (char *s, char nuevo, char viejo)
{
    for (int i = 0;s[i] != '\0';i++)
    {
        if (s[i] == 'o')
        {
            s[i] = nuevo;
        }
    }
}
