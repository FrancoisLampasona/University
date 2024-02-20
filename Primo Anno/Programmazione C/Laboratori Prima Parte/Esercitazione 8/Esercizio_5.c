#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define N 10

int main(void)
{

    char stringa_1[N];
    char stringa_2[N];
    char stringa_3[N];
    char stringa_aggiuntiva[N];

    printf("Inserisci il primo prodotto :");
    scanf("%s\n", stringa_1);

    // printf("Inserisci il secondo prodotto :");
    // scanf("%s\n", stringa_2);

    // printf("Inserisci il terzo prodotto :");
    // scanf("%s", stringa_3);

    char *token = strtok(stringa_1, " ");
    // char *token2 = strtok(stringa_1, isalnum(stringa_1));
}