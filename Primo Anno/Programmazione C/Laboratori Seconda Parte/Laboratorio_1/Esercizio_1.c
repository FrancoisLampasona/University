#include <stdio.h>
#include <stdlib.h>

int ricercabinaria(int *a, int element, int first, int last)
{
    int middle = (first + last) / 2;

    if (element == a[first])
    {
        return first;
    }
    else if (element == a[last])
    {
        return last;
    }
    else if (element == a[middle])
    {
        return middle;
    }

    if (element > a[middle])
    {
        first = middle;
        return ricercabinaria(a, element, first, last);
    }
    else if (element < a[middle])
    {
        last = middle;
        return ricercabinaria(a, element, first, last);
    }

    return -1;
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
