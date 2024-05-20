#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 10  // Definisce una costante di precompilazione N con valore 10, che rappresenta la dimensione dell'array

// Funzione di merge per fondere due sotto-array ordinati in un unico array ordinato
void merge(int *arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;  // Calcola la dimensione del primo sotto-array
    int n2 = r - m;      // Calcola la dimensione del secondo sotto-array

    // Alloca dinamicamente memoria per i due sotto-array
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copia i dati nei sotto-array temporanei L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;  // Inizializza l'indice del primo sotto-array
    j = 0;  // Inizializza l'indice del secondo sotto-array
    k = l;  // Inizializza l'indice dell'array fuso

    // Fonde i sotto-array temporanei di nuovo nell'array originale arr[l..r]
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia i rimanenti elementi di L[], se ce ne sono
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia i rimanenti elementi di R[], se ce ne sono
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Dealloca la memoria allocata per i sotto-array temporanei
    free(L);
    free(R);
}

// Funzione mergeSort che divide l'array in due metà, li ordina ricorsivamente e poi li fonde
void mergeSort(int *array, int left, int right)
{
    if (left < right)
    {
        // Calcola il punto medio dell'array per dividerlo in due metà
        int mid = left + (right - left) / 2;

        // Ordina la prima e la seconda metà
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);

        // Fonde le due metà ordinate
        merge(array, left, mid, right);
    }
}

int main(void)
{
    // Alloca dinamicamente un array di interi e lo inizializza a zero
    int *Vettore = (int *)calloc(N, sizeof(int));

    // Imposta il seme per la generazione di numeri casuali
    srand(time(NULL));

    // Riempie l'array con numeri casuali tra 0 e 15
    for (int i = 0; i < N; i++)
    {
        Vettore[i] = rand() % 16;
        printf("Numero casuale: %d \n", Vettore[i]);
    }

    // Ordina l'array usando il merge sort
    mergeSort(Vettore, 0, N - 1);

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
