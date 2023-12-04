#include <stdio.h>
#define N 5

int main(void)
{
    int V[N] = {1, 2, 1, 4, 1};
    int i;

    for (i = 0; i < N / 2; i++)
    {
        if (V[i] != V[N - i - 1])
        {
            i = N;
            printf("La seguenza non e' palindroma\n");
        }
    }

    if (i != N + 1)
    {
        printf("La sequenza e' palindroma\n");
    }
}