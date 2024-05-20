#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

int pivot(int *a, int n)
{
    return ((*(a) + *(a + n - 1)) / 2);
}

void scambia(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

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
            scambia(&*(a + f), &*(a + l));
            f++;
            l--;
        }
    }
    return f;
}

void quicksort(int *a, int f, int l)
{
    if (f < l)
    {
        int p = pivot(a + f, l - f + 1);
        int index = partition(a, f, l, p);
        quicksort(a, f, index - 1);
        quicksort(a, index, l);
    }
}

int main(void)
{
    int *V = (int *)calloc(N, sizeof(int));

    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        *(V + i) = rand() % 16;
        printf("Numero casuale: %d \n", *(V + i));
    }

    printf("Il Pivot e' %d\n", pivot(V, N));

    quicksort(V, 0, N - 1);

    printf("Array ordinato: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", *(V + i));
    }

    free(V);
    return 0;
}