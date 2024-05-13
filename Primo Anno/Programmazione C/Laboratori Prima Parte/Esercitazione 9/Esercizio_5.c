#include <stdio.h>
#define N 10

int main(void)
{

    float Matrix[N][N];
    FILE *fp;

    fp = fopen("topolino.txt", "r");

    if (fp == NULL)
    {
        printf("Errore apertura file");
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < N; k++)
        {
            fscanf(fp, "%f ", &Matrix[i][k]);
        }
    }

    int x_iniziale = 6;
    int y_iniziale = 2;
    float valore_iniziale = Matrix[y_iniziale][x_iniziale];

    for (int i = y_iniziale; i < N; i++)
    {
        for (int k = x_iniziale; k < N; k++)
        {
            /* code */
        }
        
        
    }
}