#include <stdio.h>
#include <stdlib.h>

// Funzione per trovare il valore massimo in un array
int findMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

// Funzione di ordinamento Counting Sort
void countingSort(int arr[], int n)
{
    int max = findMax(arr, n);

    // Crea un array di conteggi e inizializzalo a zero
    int *count = (int *)calloc(max + 1, sizeof(int));
    if (count == NULL)
    {
        fprintf(stderr, "Errore di allocazione della memoria\n");
        exit(1);
    }

    // Conta le occorrenze di ciascun valore
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    // Modifica l'array di conteggi in modo che ogni posizione contenga la somma delle precedenti
    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    // Costruisci l'array ordinato
    int *output = (int *)malloc(n * sizeof(int));
    if (output == NULL)
    {
        fprintf(stderr, "Errore di allocazione della memoria\n");
        free(count);
        exit(1);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copia l'array ordinato nell'array originale
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }

    // Libera la memoria allocata
    free(count);
    free(output);
}

// Funzione per stampare un array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Funzione trova minimo
int minimo(int *B, int n)
{
    int mi = B[0];
    for (int i = 1; i < n; i++)
    {
        if (B[i] < mi)
        {
            mi = B[i];
        }
    }
    return mi;
}

// Funzione trova Massimo
int massimo(int *B, int n)
{
    int ma = B[0];
    for (int i = 1; i < n; i++)
    {
        if (B[i] > ma)
        {
            ma = B[i];
        }
    }
    return ma;
}

// Funzione di ordinamento Counting Sort Ottimizzato
void counting_sort_ottimizzato(int *B, int n)
{
    // Trova il valore minimo e massimo in B
    int mi = minimo(B, n);
    int ma = massimo(B, n);

    // Determina la dimensione dell'array W
    int N = ma - mi + 1;

    // Allocazione dinamica dell'array W e inizializzazione a zero
    int *W = calloc(N, sizeof(int));

    // Conteggio delle occorrenze di ciascun valore in B
    for (int i = 0; i < n; i++)
    {
        W[B[i] - mi]++;
    }

    // Ricostruzione dell'array ordinato B
    int k = 0; // indice per l'array B
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < W[i]; j++)
        {
            B[k++] = i + mi;
        }
    }

    // Deallocazione della memoria per l'array W
    free(W);
}

int main()
{
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array originale:\n");
    printArray(arr, n);

    countingSort(arr, n);

    printf("\nArray Counting Sort:\n");
    printArray(arr, n);

    printf("\nArray Counting Sort Ottimizzato:\n");
    printArray(arr, n);

    return 0;
}
