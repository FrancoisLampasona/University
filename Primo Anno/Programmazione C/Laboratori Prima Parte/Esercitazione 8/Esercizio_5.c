#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 15

int main(void)
{

    char stringa_matrix[3][N];
    char stringa_aggiuntiva[N];
    int prezzo, quantita;

    for (int i = 0; i < 3; i++)
    {
        printf("Inserisci il %d^ prodotto :", i + 1);
        fgets(stringa_matrix[i], N, stdin);
    }

    printf("Inserisci il prodotto e la quantita :");
    fgets(stringa_aggiuntiva, N, stdin);

    char *token_nome_aggiuntivo = strtok(stringa_aggiuntiva, " ");
    char *token_quanto_aggiuntivo = strtok(NULL, " ");
    quantita = atoi(token_quanto_aggiuntivo);

    for (int i = 0; i < 3; i++)
    {
        char *token = strtok(stringa_matrix[i], " ");
        if (token != NULL)
        {
            if (strcmp(token_nome_aggiuntivo, token) == 0)
            {
                token = strtok(NULL, " ");
                prezzo = atoi(token);
                printf("Il prezzo totale e' %d", quantita * prezzo);
            }
        }
    }
}
