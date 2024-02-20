#include <stdio.h>
#define N 5

int power(int base, int exponent);

int main()
{

    int vbase[N];
    int vesponente[N];
    int vres[N];

    for (int i = 0; i < N; i++)
    {
        printf("Inserisci il valore della base %d :", i+1);
        scanf("%d", &vbase[i]);
        printf("Inserisci il valore dell'esponente %d :", i+1);
        scanf("%d", &vesponente[i]);
    }

    for (int i = 0; i < N; i++)
    {
        power(vbase[i],vesponente[i]);
    }
    

}

int power(int base, int esponente)
{

    int ris = 1;

    while (esponente > 0)
    {
        ris *= base;
        esponente--;
    }

    printf("Il risultato e' : %d\n",ris);
}