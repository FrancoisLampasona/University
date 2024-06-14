#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findmin(const int *a, const size_t n)
{
    if (n == 1)
    {
        return a[0];
    }
    else
    {
        int min_rest = findmin(a, n - 1);
        if (a[n - 1] < min_rest)
        {
            return a[n - 1];
        }
        else
        {
            return min_rest;
        }
    }
}

int main(void)
{
    int *V = (int *)malloc(sizeof(int) * 10);
    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        V[i] = rand() % 10;
        printf("%d ", V[i]);
    }
    printf("\n%d", findmin(V, 10));
}