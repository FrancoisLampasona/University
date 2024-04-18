#include <stdio.h>
#define N 5
#define M 10

int insert_product(char warehouse[][M], float price[], int n, char new_product[], float price_new_product);

int main(void)
{
    char Matrix[N][M];
    int price[N] = {-2};
    int scelta = 0;

    while (scelta != 3)
    {
        printf("Inserisci l'opzione: ");
        scanf("%d", scelta);

        switch (scelta)
        {
        case 1:
            printf("Inserimento di un nuovo prodotto\n");
            break;

        case 2:
            printf("Listino prezzi\n");

            for (int i = 0; i < N; i++)
            {
                printf("Il prodotto ");
                for (int k = 0; k < M; k++)
                {
                    printf("%c", Matrix[i][k]);
                }
                printf("ha prezzo : %d\n", price[i]);
            }
        case 3:
            printf("Escita dal programma avvenuta\n");
            exit(0);
        default:
            printf("Nessuna azione associata");
            break;
        }
    }
}

int insert_product(char warehouse[][M], float price[], int n, char new_product[], float price_new_product){
    
}
