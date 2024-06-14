#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int pivot(int *a, int n)
{
    return (*(a) + a[n - 1]) / 2;
}

int partition(int *a, int f, int l, int pivot)
{
    int temp;
    while (f <= l)
    {
        while (*(a + f) < pivot)
        {
            f++;
        }
        while (*(a + l) > pivot)
        {
            l--;
        }
        if (f <= l)
        {
            temp = *(a + f);     // dato che a[l] dovrà stare nella partizione di sinistra e
            *(a + f) = *(a + l); // a[f] nella partizione di destra.
            *(a + l) = temp;
            f++; // Avendo posizionato a[f] e a[l] nelle corrispettive partizioni,
            l--; //
        }
    }
    return l;
}

void quicksort(int *a, int f, int l)
{
    if (f < l)
    {                                    // Se f<l...
        int p = pivot(a + f, l - f + 1); //...calcolo il pivot
        int pos = partition(a, f, l, p); //...partiziono l'array in base al pivot
        if (pos < l)                     //(per evitare di richiamare la funzione sullo stesso input)
            quicksort(a, f, pos);        //...richiamo il quicksortsulla partizione di sinistra
        if (pos + 1 > f)                 //(per evitare di richiamare la funzione sullo stesso input)
            quicksort(a, pos + 1, l);    //...e richiamo il quicksortsulla partizione di destra
    }
}

int main(void)
{
    int *V = (int *)calloc(10, sizeof(int));
    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        V[i] = rand() % 12;
    }

    quicksort(V, 0, 9);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", V[i]);
    }
}