#include <stdio.h>
#define N 10

int main(void)
{
    int media;
    int somma = N, count = 0;
    int numero;

    do
    {
        printf("Inserisci il numero :");
        scanf("%d", &numero);
        count++;
        somma += numero;
        media = somma / count;

    } while (media > N && count < N);

    printf("La media dei numeri inseriti e' %d", somma / count);
}