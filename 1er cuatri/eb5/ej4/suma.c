void matriz_vector (int ** vector, int tam_vector)
{
    int suma = 0;
    
    for (int i = 0;i < tam_vector;i++)
    {
        for (int j = 0;j < tam_vector;j++)
        {
            if (i == j)
            {
                suma += vector [i][j]; 
            }        
        }
    }
    printf ("El resultado de la suma es: %d\n", suma);
}
