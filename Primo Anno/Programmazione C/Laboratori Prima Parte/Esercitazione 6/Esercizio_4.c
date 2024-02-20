#include <stdio.h>
#define N 5

int main(void)
{
    int V[N];
    int numero;

    for (int i = 0; i < N; i++)
    {
        printf("Inserisci un valore nel vettore :");
        scanf("%d", &numero);

        if (i == 0)
        {
            V[i] = numero;
        }

        for (int j = i - 1; j >= 0; j--)
        {
            if (numero > V[j])
            {

                V[j + 1] = numero;
                j = -1;
            }
            else
            {
                V[j + 1] = V[j];
                V[j] = numero;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        printf(" %d ", V[i]);
    }
}