#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void bubbleSort(int *array, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            // Se l'elemento successivo è minore dell'elemento corrente, scambiali
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main(void)
{
    // Alloca dinamicamente un array di interi e lo inizializza a zero
    int *array = (int *)calloc(N, sizeof(int));

    // Imposta il seme per la generazione di numeri casuali
    srand(time(NULL));

    // Riempie l'array con numeri casuali tra 0 e 15 e stampa i numeri generati
    printf("Numeri casuali: ");
    for (int i = 0; i < N; i++)
    {
        array[i] = rand() % 16;
        printf("%d ", array[i]);
    }
    printf("\n");

    // Ordina l'array usando l'ordinamento a bolle (Bubble Sort)
    bubbleSort(array, N);

    // Stampa l'array ordinato
    printf("Array ordinato: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Dealloca la memoria allocata per l'array
    free(array);
    return 0;
}
