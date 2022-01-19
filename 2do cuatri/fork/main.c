#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void handler (int sig);

int main ()
{
    pid_t pid;
    char nombre[50];
    pid = fork();

    if (pid == 0)
    {
        //Child
        for (int s = 0;s < 60;s++)
        {
            printf ("Van %d segundos \n",s);
            signal (SIGUSR1, handler);
            sleep (1);
        }
    }
    else if (pid > 0)
    {
        //Parent
        printf ("Ingrese su nombre: \n");
        scanf ("%s", nombre);
        kill (0,SIGUSR1);
    }
    else if (pid == -1)
    {
        //Error
        printf ("Error\n");
    }
    return 0;
}

void handler (int sig)
{
    printf ("Gracias por ingresar su nombre\n");
    exit (0);
}