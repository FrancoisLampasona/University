#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

// Funzione per calcolare il pivot
int pivot(int *a, int n)
{
    return ((*(a) + *(a + n - 1)) / 2);
}

// Funzione per lo scambio di due valori
void scambia(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Funzione di partizione per l'algoritmo di ordinamento quicksort
int partition(int *a, int f, int l, int pivot)
{
    while (f <= l)
    {
        while (*(a + f) < pivot)
            f++;
        while (*(a + l) > pivot)
            l--;

        if (f <= l)
        {
            scambia(&*(a + f), &*(a + l)); // Scambio di due valori
            f++;
            l--;
        }
    }
    return f;
}

// Funzione ricorsiva per l'ordinamento dell'array mediante quicksort
void quicksort(int *a, int f, int l)
{
    if (f < l)
    {
        int p = pivot(a + f, l - f + 1);   // Calcolo del pivot
        int index = partition(a, f, l, p); // Partizionamento dell'array
        quicksort(a, f, index - 1);        // Ordinamento della parte sinistra dell'array
        quicksort(a, index, l);            // Ordinamento della parte destra dell'array
    }
}

int main(void)
{
    // Allocazione dinamica dell'array di dimensione N
    int *V = (int *)calloc(N, sizeof(int));

    // Inizializzazione del generatore di numeri casuali
    srand(time(NULL));

    // Generazione e stampa di numeri casuali nell'array
    for (int i = 0; i < N; i++)
    {
        *(V + i) = rand() % 16;
        printf("Numero casuale: %d \n", *(V + i));
    }

    // Calcolo e stampa del pivot
    printf("Il Pivot e' %d\n", pivot(V, N));

    // Ordinamento dell'array mediante quicksort
    quicksort(V, 0, N - 1);

    // Stampa dell'array ordinato
    printf("Array ordinato: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", *(V + i));
    }

    // Liberazione della memoria allocata per l'array
    free(V);
    return 0;
}