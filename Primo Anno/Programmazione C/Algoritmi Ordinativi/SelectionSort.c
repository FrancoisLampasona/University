#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

// Funzione per scambiare due elementi di un array
void swap(int *Vettore, int i, int indice_min)
{
    int tmp = Vettore[i];
    Vettore[i] = Vettore[indice_min];
    Vettore[indice_min] = tmp;
}

// Funzione di ordinamento per selezione
void selectionSort(int *Vettore, int len)
{
    // Scansiona l'array
    for (int i = 0; i < len - 1; i++)
    {
        int indice_min = i;
        // Trova l'indice del minimo elemento nella parte non ordinata dell'array
        for (int k = i + 1; k < len; k++)
        {
            if (Vettore[k] < Vettore[indice_min])
            {
                indice_min = k;
            }
        }
        // Scambia l'elemento corrente con il minimo trovato
        if (indice_min != i)
        {
            swap(Vettore, i, indice_min);
        }
    }
}

int main(void)
{
    // Alloca dinamicamente un array di interi e lo inizializza a zero
    int *Vettore = (int *)calloc(N, sizeof(int));

    // Imposta il seme per la generazione di numeri casuali
    srand(time(NULL));

    // Riempie l'array con numeri casuali tra 0 e 15 e stampa i numeri generati
    for (int i = 0; i < N; i++)
    {
        Vettore[i] = rand() % 16;
        printf("Numero casuale: %d \n", Vettore[i]);
    }

    // Ordina l'array usando l'ordinamento per selezione
    selectionSort(Vettore, N);

    // Stampa l'array ordinato
    printf("Array ordinato: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", Vettore[i]);
    }
    printf("\n");

    // Dealloca la memoria allocata per l'array
    free(Vettore);
    return 0;
}
