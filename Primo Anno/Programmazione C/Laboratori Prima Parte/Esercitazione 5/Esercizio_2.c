#include <stdio.h>
#define N 5

int main(void)
{
    int V[N];
    float media;
    int max, posizione[N], count = 0;

    for (int i = 0; i < N; i++)
    {
        printf("Insersci il %d^ numero nel vettore : ", i + 1);
        scanf("%d", &V[i]);
    }

    max = V[0];

    for (int i = 0; i < N; i++)
    {
        printf("Nella posizione [%d] c'e' il numero %d\n", i, V[i]);
        media += V[i];
        if (max <= V[i] && i != 0)
        {
            if (max == V[i])
            {
                posizione[count] = i;
                count++;
            }
            max = V[i];
            posizione[count] = i;
        }
    }

    printf("La media e' %.2f\n", (float)media / N);

    if (count >= 1)
    {
        printf("Il massimo e' %d presente nella posizione ", max);
        for (int i = 0; i <= count; i++)
        {
            printf("%d  ", posizione[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Il massimo e' %d e la sua posizione e' %d \n", max, posizione[count]);
    }
}