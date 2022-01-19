#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define TAM 100

int main ()
{
    int cuenta [TAM];
    int numero, n = 0;
    int i;
    float promedio;


    for (i = 0; i < MAX ; i++)
    {    
          do
          {
            numero = rand() % MAX;
            cuenta [i] =  numero;  
            
          }while ( numero == n );  
          promedio = cuenta [TAM] / i;
          printf ("El promedio es %d \n", promedio);             
              
         n ++;
       
        
    } 

    return 0;
}
