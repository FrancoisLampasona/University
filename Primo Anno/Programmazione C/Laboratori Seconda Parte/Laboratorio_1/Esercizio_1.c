#include <stdio.h>
#include <stdlib.h>

int ricercabinaria(int *a, int element, int first, int last)
{
    if (first > last)
    {
        return -1;
    }

    int middle = (first + last) / 2;

    if (a[middle] == element)
    {
        return middle;
    }
    else if (a[middle] > element)
    {
        return ricercabinaria(a, element, first, middle - 1);
    }
    else if (a[middle] < element)
    {
        return ricercabinaria(a, element, middle + 1, last);
    }
}

int main(void)
{
    int *a = calloc(10, sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        a[i] = i;
        printf("%d ", a[i]);
    }

    int ritorno = ricercabinaria(a, 5, 0, 9);
    printf("\nl'indice e': %d", ritorno);

    free(a);
}
