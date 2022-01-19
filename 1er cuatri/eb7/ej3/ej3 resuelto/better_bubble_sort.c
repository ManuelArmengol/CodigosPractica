#include <stdbool.h>





/**
 * Metodo de ordenamiento "de intercambio" o "de burbuja" con detección de orden prematuro
 */
void better_bubble_sort (int * vector, int length, char (*comparacion) (int num1, int num2))
{
     int i, j;
     int aux;
     bool ordenado;


     for (i = 1; i < length; i++)
     {
          ordenado = true;

          for (j = 0; j < length - i; j++)
          {
               if (comparacion (vector [j], vector [j + 1]))
               {
                    ordenado = false;
                    
                    aux            = vector [j + 1];
                    vector [j + 1] = vector [j];
                    vector [j]     = aux;
               }
          }

          if (ordenado)
          {
               break;
          }
     }
}
