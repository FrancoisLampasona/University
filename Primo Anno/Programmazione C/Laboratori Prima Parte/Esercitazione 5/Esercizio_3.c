#include <stdio.h>
#define N 5

int main(void)
{
    int V1[N], indice1 = 0;
    int V2[N], indice2 = 0;
    int a;

    do
    {
        printf("Inserisci un valore nei vettori : ");
        scanf("%d", &a);

        if (a > 0 || (a < 0 && a % 3 == 0))
        {
            V1[indice1] = a;
            indice1++;
        }
        else if (a < 0 && a % 3 != 0 && a % 2 != 0)
        {
            V2[indice2] = a;
            indice2++;
        }

    } while (indice1 < N && indice2 < N);

    for (int i = 0; i < indice1; i++)
    {
        printf("V1[%d] = %d\n", i, V1[i]);
    }
    printf("\n");
    for (int i = 0; i < indice2; i++)
    {
        printf("V2[%d] = %d\n", i, V2[i]);
    }
}