#include <stdio.h>
#define N 10

int main(void)
{

    int V[N];
    int indice = 2, count = 0;

    printf("Inserisci il numero nel vettore: ");
    scanf("%d", &V[0]);

    printf("Inserisci il numero nel vettore: ");
    scanf("%d", &V[1]);

    if (V[0] < V[1])
    {
        do
        {

            printf("Inserisci il numero nel vettore: ");
            scanf("%d", &V[indice]);

            if (V[indice] > V[indice - 1])
            {
                indice++;
            }
            else
            {
                count = indice;
                indice = N;
            }

        } while (indice < N);
    }
    else
    {
        do
        {
            printf("Inserisci il numero nel vettore: ");
            scanf("%d", &V[indice]);

            if (V[indice] < V[indice - 1])
            {
                indice++;
            }
            else
            {
                count = indice;
                indice = N;
            }

        } while (indice < N);
    }

    for (int i = 0; i < count+1; i++)
    {
        printf("%d ", V[i]);
    }
}