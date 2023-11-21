#include <stdio.h>
#define N 5

int main(void)
{
    int V[N], indiceV = 0;
    int Posizione[N], indiceP = 0;
    int a;

    do
    {
        printf("Inserisci i valori nel vettore:");
        scanf("%d", &a);
        if (a >= 0)
        {
            V[indiceV] = a;
            indiceV++;
        }
        else
        {
            indiceV = N;
        }
    } while (indiceV < N);

    printf("\n");

    do
    {
        printf("Inserisci il valore da cercare:");
        scanf("%d", &a);

        for (int i = 0; i < indiceV; i++)
        {
            if (V[i] == a)
            {
                Posizione[indiceP] = i;
                indiceP++;
            }
        }
        printf("Il valore %d e' nella posizione ", a);

        if (indiceP > 1)
        {
            for (int i = 0; i < indiceP; i++)
            {
                printf("%d ", Posizione[i]);
            }
        }
        else
        {
            printf("%d",Posizione[indiceP - 1]);
        }
    } while (a < 0);
}