#include <stdio.h>

int minarray(const int *a, const size_t n)
{

    if (n == 1)
    {
        return a[0];
    }
    else
    {
        int min_rest = minarray(a, n - 1);
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
    int V[5] = {1, 2, 0, 4, -4};
    printf("%d", minarray(V, 5));
}