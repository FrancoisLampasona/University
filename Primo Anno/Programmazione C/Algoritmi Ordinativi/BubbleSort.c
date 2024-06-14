#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void bubbleSort(int *arr, int n)
{
    int swapped; // Variabile per tenere traccia se è avvenuto uno scambio
    // Ciclo esterno per passare attraverso tutti gli elementi dell'array
    for (int i = 0; i < n - 1; i++)
    {
        swapped = 0; // Resetta la variabile swapped ad ogni iterazione del ciclo esterno
        // Ciclo interno per confrontare gli elementi adiacenti e scambiarli se necessario
        for (int j = 0; j < n - i - 1; j++)
        {
            // Controlla se l'elemento corrente è maggiore del prossimo elemento
            if (arr[j] > arr[j + 1])
            {
                // Se sì, scambia i due elementi
                int temp = arr[j];   // Variabile temporanea per memorizzare il valore di arr[j]
                arr[j] = arr[j + 1]; // Copia il valore di arr[j+1] in arr[j]
                arr[j + 1] = temp;   // Copia il valore temporaneo in arr[j+1]
                swapped = 1;         // Imposta swapped a 1 per indicare che è avvenuto uno scambio
            }
        }
        // Se non è avvenuto alcuno scambio durante l'iterazione del ciclo interno, l'array è già ordinato
        if (swapped == 0)
        {
            break; // Esci dal ciclo esterno anticipatamente
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
