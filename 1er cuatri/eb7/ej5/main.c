#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void string_reverse (char * argv);

int main (int argc, char * argv [])
{
    string_reverse (argv);

    return 0;
}

void string_reverse (char * argv)
{
    int n = atoi (argv[2]);
    int * vector [2];

    for (int i = 0;i < n;i++)
    {
        do 
        {
            vector [i] = vector [i + 1];
        }while (i != n)
    }
    printf ("La frase shifteada es: %s \n",vector);
}
