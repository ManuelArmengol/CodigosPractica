#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void pascal_vector (char s[]);

int main ()
{
    char s[50];
    
    printf ("Ingrese una frase\n");
    fgets (s,50,stdin);

    pascal_vector (s);

    printf ("Conversion a Pascal Case: %s", s);    

    return 0;
}

void pascal_vector (char s[])
{
    s[0] = toupper(s[0]);

    for (int i = 0;s[i] != '\0';i++)
    {        
        int j;
        if (s[i] == 32)
        {          
            j = i;
        }
        if (i >= j)
        {
            s[i] = s[i + 1];
            s[j] = toupper (s[j]);
        }
    }
}
