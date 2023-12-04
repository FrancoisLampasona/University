#include <stdio.h>
#define N 5

int main(void)
{
    int V[N]; /*= {1, 3, 3, 3, 1};*/

    for (int i = 0; i < N; i++)
    {
        printf("Inserisci i valori nel vettore : ");
        scanf("%d", &V[i]);
    }

    int ricercatore = 0;
    int stampato = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (V[j] == V[i])
            {
                stampato = 1;
                j = i;
            }
        }

        if (stampato == 0)
        {
            for (int k = 0; k < N; k++)
            {

                if (V[i] == V[k])
                {
                    ricercatore++;
                }
            }
            if (ricercatore > 1)
            {
                printf("Il numero %d e' presente %d volte\n", V[i], ricercatore);
            }
            ricercatore = 0;
        }
        stampato = 0;
    }
}