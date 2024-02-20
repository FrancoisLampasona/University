#include <stdio.h>
#define N 9

int main(void)
{

    for (int i = 1; i < N; i++)
    {
        for (int k = 0; k < i; k++)
        {
            printf("*");
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i <= N/2; i++)
    {
        for (int k = 0; k < N - i * 2; k++)
        {
            printf("*");
        }

        printf("\n");

        for (int j = 0; j <= i ; j++)
        {
            printf(" ");
        }
    }
}