#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void InsertionSort(int *array, int len)
{
    // Scorre l'array partendo dal secondo elemento (indice 1)
    for (int i = 1; i < len; i++)
    {
        // Memorizza l'elemento corrente da inserire nella parte ordinata dell'array
        int key = array[i];
        // Imposta j come l'indice dell'elemento prima di quello corrente
        int j = i - 1;

        // Sposta gli elementi di array[0..i-1] che sono maggiori di key
        // nella loro posizione successiva rispetto alla posizione corrente
        while (j >= 0 && array[j] > key)
        {
            // Sposta l'elemento array[j] in avanti di una posizione
            array[j + 1] = array[j];
            // Decrementa j per confrontare il key con l'elemento precedente
            j = j - 1;
        }
        // Posiziona key nella posizione corretta all'interno della parte ordinata dell'array
        array[j + 1] = key;
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
    InsertionSort(Vettore, N);

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