#include <stdio.h>
#define N 5

void mult(int V[], int n, int x);

int main(void)
{

    int vett[N], x;

    for (int i = 0; i < N; i++)
    {
        printf("Inserisci i valori nel vettore :");
        scanf("%d", &vett[i]);
    }

    printf("Inserisci un valore x :");
    scanf("%d", &x);

    mult(vett, N, x);

    for (int i = 0; i < N; i++)
    {
        printf("%d ", vett[i]);
    }
}

void mult(int V[], int n, int x)
{

    for (int i = 0; i < n; i++)
    {
        V[i] *= x;
    }
}