#include <stdio.h>
#define N 5

int main(void)
{
    int Matrix[N][N] = {{0, 0, 0, 4, 5}, {1, 2, 0, 4, 5}, {1, 0, 0, 4, 0}, {1, 2, 3, 4, 5}, {1, 0, 0, 0, 0}};
    int flagRiga = 0;
    int flagColonna = 0;
    int lunghezza = 3;
    int valore = 0;

    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < N; k++)
        {
            if (Matrix[i][k] == valore)
            {
                flagRiga++;
                if (flagRiga >= lunghezza)
                {
                    printf("La sequenza compare nella riga %d\n", i + 1);
                    flagRiga = 0;
                }
            }
            else
            {
                flagRiga = 0;
            }

            if (Matrix[k][i] == valore)
            {
                flagColonna++;
                if (flagColonna >= lunghezza)
                {
                    printf("La sequenza compare nella colonna %d\n", i + 1);
                    flagColonna = 0;
                }
            }
            else
            {
                flagColonna = 0;
            }
        }
    }
}