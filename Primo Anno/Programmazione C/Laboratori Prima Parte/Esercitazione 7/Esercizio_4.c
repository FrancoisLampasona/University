#include <stdio.h>
#define N 5

float avgVect(int v[], int n);
int upperLimit(int v[], int n, float limit);

int main(void)
{

    int V[N];
    int valore = 15;

    for (int i = 0; i < N; i++)
    {
        printf("Inserisci il valore nel vettore:");
        scanf("%d", &V[i]);
    }

    int media = avgVect(V, N);
    int limite = upperLimit(V, N, valore);

    printf("La media degli elementi e' : %d\n",media);
    printf("Il limite e' stato superato : %d volte",limite);
}

float avgVect(int v[], int n)
{
    int media = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        media += v[i];
    }

    return media / i;
}
int upperLimit(int v[], int n, float limit)
{
    int counter = 0;

    for (int i = 0; i < n; i++)
    {
        if (v[i] > limit)
        {
            counter++;
        }
    }

    return counter;
}