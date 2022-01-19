/*******************************************
 *          INCLUDES
 *******************************************/
#include <stdio.h>
#include <math.h> // pow





/*******************************************
 *          LOCAL FORWARDS
 *******************************************/

char num_length (int num);
char get_digit (int num, char digit_pos);





/*******************************************
 *          PUBLIC FUNCTIONS
 *******************************************/

char comparacion (int num_1, int num_2)
{
    /* Primero comparo el primer digito,
     * si son iguales comparo el siguiente y así
     */

    char digit_pos = 0;
    char digit_1;
    char digit_2;
    char length_1 = num_length (num_1);
    char length_2 = num_length (num_2);

    do
    {
        digit_1 = get_digit (num_1, length_1 - digit_pos);
        digit_2 = get_digit (num_2, length_2 - digit_pos);
        digit_pos ++;
        if (digit_pos > length_1 && digit_pos > length_2)
        {
            break; // Esto es para salir del while en caso que ambos numeros sean iguales
        }
    } while (digit_1 == digit_2);

    return digit_1 < digit_2;
}

long long int unir_vector (int *vector, int length)
{
    long long int unido = 0;
    int i;

    for (i = 0; i < length; i ++)
    {
        unido *= pow (10, num_length (vector [i]));
        unido += vector [i];
    }

    return unido;
}





/*******************************************
 *          PRIVATE FUNCTIONS
 *******************************************/

char num_length (int num)
{
    int i;

    for (i = 0; num != 0; i++)
    {
        num /= 10;
    }
    if (0 == i) i = 1;

    return i;
}

/* Obtiene un digito. la posicion 0 es
 * el digito de mas a la derecha
 */
char get_digit (int num, char digit_pos)
{
    char digit = 0;
    int i;

    if (digit_pos < 0)
    {
        return num % 10; // Si la posicion es menor a 0, devuelvo el ultimo digito
    }

    for (i = 0; i <= digit_pos && num != 0; i++)
    {
        digit = num % 10;
        num /= 10;
    }

    return digit;
}