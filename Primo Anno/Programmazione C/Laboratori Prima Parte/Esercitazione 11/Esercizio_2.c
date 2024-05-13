#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PERSONE 100
#define RIGHE 80

struct Names
{
    char nome[20];
    char cognome[20];
    char fisso[20];
    char mobile[20];
};

typedef struct Names nomi;

void inseriscinome(nomi nomi[], char nome[], char cognome[], char fisso[], char mobile[], int *indice)
{
    char scelta = 'f';

    for (int i = 0; i < *indice; i++)
    {
        if (strcmp(nomi[i].nome, nome) == 0 && strcmp(nomi[i].cognome, cognome) == 0)
        {
            printf("La persona e' gia presente \n");
            printf("Vuoi inserire comunque ? Y / N\n");
            getchar();
            scanf("%c", &scelta);
            if (scelta == 'Y')
            {
                strcpy(nomi[*indice].nome, nome);
                strcpy(nomi[*indice].cognome, cognome);
                strcpy(nomi[*indice].fisso, fisso);
                strcpy(nomi[*indice].mobile, mobile);
                (*indice)++;
            }
            return;
        }
    }

    if (scelta == 'f')
    {
        strcpy(nomi[*indice].nome, nome);
        strcpy(nomi[*indice].cognome, cognome);
        strcpy(nomi[*indice].fisso, fisso);
        strcpy(nomi[*indice].mobile, mobile);
        (*indice)++;
    }
}

void stampanomi(nomi nomi[], int indice)
{
    for (int i = 0; i < indice; i++)
    {
        printf("%s ", nomi[i].nome);
        printf("%s ", nomi[i].cognome);
        printf("%s ", nomi[i].fisso);
        printf("%s \n", nomi[i].mobile);
    }
    printf("\n");
}

int main(int argc, const char *argv[])
{
    nomi persone[100];
    int scelta = 5;
    int indice = 0;

    strcpy(persone[indice].nome, "Marta");
    strcpy(persone[indice].cognome, "Femin");
    strcpy(persone[indice].fisso, "345092");
    strcpy(persone[indice].mobile, "0983");
    indice++;

    strcpy(persone[indice].nome, "Luca");
    strcpy(persone[indice].cognome, "Rossi");
    strcpy(persone[indice].fisso, "456123");
    strcpy(persone[indice].mobile, "0765");
    indice++;

    strcpy(persone[indice].nome, "Anna");
    strcpy(persone[indice].cognome, "Bianchi");
    strcpy(persone[indice].fisso, "789456");
    strcpy(persone[indice].mobile, "0321");
    indice++;

    strcpy(persone[indice].nome, "Marco");
    strcpy(persone[indice].cognome, "Verdi");
    strcpy(persone[indice].fisso, "159753");
    strcpy(persone[indice].mobile, "0412");
    indice++;

    strcpy(persone[indice].nome, "Chiara");
    strcpy(persone[indice].cognome, "Gialli");
    strcpy(persone[indice].fisso, "753951");
    strcpy(persone[indice].mobile, "0654");

    while (scelta != 0)
    {
        printf("Inserisci una scelta : ");
        scanf("%d", &scelta);
        switch (scelta)
        {
        case 1:
            inseriscinome(persone, "Andrea", "Belmont", "0923", "34092", &indice);
            break;
        case 2:
            stampanomi(persone, indice);
            break;

        default:
            break;
        }
    }
}