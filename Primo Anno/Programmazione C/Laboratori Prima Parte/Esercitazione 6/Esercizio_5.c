#include <stdio.h>

int power(int base, int esponente);

int main(void)
{

    int base, esponente;

    printf("Inserisci il numero corrispondente alla base : ");
    scanf("%d", &base);

    printf("Inserisci il numero corrispondente all'esponente : ");
    scanf("%d", &esponente);

    int risultato = power(base, esponente);

    printf("Il risulato e' : %d", risultato);
}

int power(int base, int esponente)
{
    int s = 1;
    for (int i = 0; i < esponente; i++)
    {
        s *= base;
    }

    return s;
}