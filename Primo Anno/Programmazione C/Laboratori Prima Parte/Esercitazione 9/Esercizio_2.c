#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5
#define M 10

int insert_product(char warehouse[][M], float price[], char new_product[], float price_new_product);
void print_all(char warehouse[][M], float price[], float *avg, float *max);

int main(void)
{
    char Matrix[N][M];
    float price[N];
    int scelta = 0;
    float prezzo_medio = 0, prezzo_max = 0;

    for (int i = 0; i < N; i++)
    {
        price[i] = -2;
    }

    while (scelta != 3)
    {
        printf("\nScegli 3 possibili operazioni : \n");
        printf("1) Inserimento di un nuovo prodotto e relativo prezzo\n");
        printf("2) Stampa listino attuale (elenco dei prodotti con i relativi prezzi)\n");
        printf("3) Uscita dal programma\n");
        printf("Inserisci l'opzione: ");
        scanf("%d", &scelta);
        getchar(); // Pulizia del buffer di input

        switch (scelta)
        {
        case 1:
            printf("Inserimento di un nuovo prodotto : \n");

            char new_product[M];
            float price_new_product;

            printf("Inserisci il nome del nuovo prodotto :");
            fgets(new_product, M, stdin);

            if (strchr(new_product, '\n') == NULL)
            {
                // Pulizia del buffer di input
                int c;
                while ((c = getchar()) != '\n' && c != EOF)
                    ;
            }

            int len = strlen(new_product);
            if (new_product[len - 1] == '\n')
            {
                new_product[len - 1] = '\0';
            }

            printf("Inserisci il prezzo del nuovo prodotto :");
            scanf("%f", &price_new_product);

            insert_product(Matrix, price, new_product, price_new_product);

            break;

        case 2:
            printf("Listino prezzi\n");
            print_all(Matrix, price, &prezzo_medio, &prezzo_max);
            printf("Prezzo medio: %.2f\n", prezzo_medio / N);
            printf("Prezzo massimo: %.2f\n", prezzo_max);
            break;
        case 3:
            printf("Uscita dal programma avvenuta\n");
            return 0; // Uscita da main()
        default:
            printf("Nessuna azione associata\n");
            break;
        }
    }
}

int insert_product(char warehouse[][M], float price[], char new_product[], float price_new_product)
{
    for (int i = 0; i < N; i++)
    {
        if (price[i] == -2)
        {
            strcpy(warehouse[i], new_product);
            price[i] = price_new_product;
            return 1;
        }
        else if (strcmp(new_product, warehouse[i]) == 0)
        {
            printf("Il prodotto e' gia presente nel listino\n");
            return 0;
        }
    }
    printf("Il listino e' pieno\n");
    return 2;
}

void print_all(char warehouse[][M], float price[], float *avg, float *max)
{
    for (int i = 0; i < N; i++)
    {
        if (price[i] != -2)
        {
            *avg += price[i];
            printf("Il prodotto %s ha prezzo %.2f\n", warehouse[i], price[i]);
            if (*max < price[i])
            {
                *max = price[i];
            }
        }
    }
}
