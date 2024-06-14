#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Algoritmi_Ordinativi.h"
#define N 10

int main(void)
{

    int Vettore[N];

    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        Vettore[i] = rand() % 10;
        printf("%d ", Vettore[i]);
    }

    bubble_sort(Vettore, N);

    printf("\n");

    stampa_array(Vettore, N);
}