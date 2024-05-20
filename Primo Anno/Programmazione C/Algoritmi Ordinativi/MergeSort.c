#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

int main(void)
{
    int *Vettore = (int *)calloc(N, sizeof(int));

    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        *(Vettore + i) = rand() % 16;
        printf("Numero casuale: %d \n", *(Vettore + i));
    }

    printf("Array ordinato: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", *(Vettore + i));
    }

    free(Vettore);
    return 0;
}