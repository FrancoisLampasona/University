#include <stdio.h>
#define N 5

int main(void)
{

    int numero, resto, j, flag;
    int V[N] = {};
    int indice = 0;

    printf("Inserisci il numero che vuoi verificare : ");
    scanf("%d", &numero);

    for (int i = 2; i <= N; i++)
    {
        flag = numero;

        while (numero > 0)
        {
            resto = numero % i;
            numero = numero / i;
            V[indice] = resto;
            indice++;
        }

        for (j = 0; j < indice / 2; j++)
        {
            if (V[j] != V[indice - j - 1])
            {
                j = indice;
                printf("Il numero non e' palindromo nella base %d \n", i);
            }
        }

        if (j != indice + 1)
        {
            printf("Il numero e' palindromo in base %d\n", i);
        }

        indice = 0;
        numero = flag;
    }
}