#include <stdio.h>
#define N 14

int main(void)
{

    int V[N] = {1, 2, 3, 4, 5,7,8,4,12,31,4,2,1};

    for (int i = 0; i < N-1; i++)
    {

        if (V[i] < V[i + 1] && V[i + 1] < V[i + 2])
        {

            printf("La serie è : %d %d %d\n", V[i], V[i + 1], V[i + 2]);
            printf("La posizione è : [%d]\n\n", i);
        }
    }
}