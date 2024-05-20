#include <stdio.h>
#include <stdlib.h>

typedef struct DoubleLinkedList
{
    int valore;
    struct DoubleLinkedList *precedente;
    struct DoubleLinkedList *next;
} Nodo;

void inserimento_in_testa(Nodo **testa, Nodo **coda, int valore)
{

    Nodo *new_nodo = (Nodo *)malloc(sizeof(Nodo));
    if (!new_nodo)
    {
        printf("Errore allocazione memoria \n");
        exit(1);
    }

    new_nodo->valore = valore;
    new_nodo->precedente = NULL;

    if (*testa == NULL)
    {
        new_nodo->next = NULL;
        *testa = new_nodo;
        *coda = new_nodo;
    }
    else
    {
        new_nodo->next = *testa;
        (*testa)->precedente = new_nodo;
        (*testa) = new_nodo;
    }
}

void stampa_lista_doppiamente_concatenata_testa(Nodo *testa)
{

    Nodo *current = testa;

    while (current != NULL)
    {
        printf("%d", current->valore);
        if (current->next != NULL)
        {
            printf(" --> ");
        }
        current = current->next;
    }
    printf("\n");
}

void stampa_lista_doppiamente_concatenata_testa_ricorsivo(Nodo *testa)
{

    if (testa != NULL)
    {
        printf("%d", testa->valore);
        if (testa->next != NULL)
        {
            printf(" --> ");
        }
        stampa_lista_doppiamente_concatenata_testa(testa->next);
    }
}

int main(void)
{
    Nodo *testa = NULL;
    Nodo *coda = NULL;
    int valore = 1;

    inserimento_in_testa(&testa, &coda, valore++);
    inserimento_in_testa(&testa, &coda, valore++);
    inserimento_in_testa(&testa, &coda, valore++);
    inserimento_in_testa(&testa, &coda, valore++);
    inserimento_in_testa(&testa, &coda, valore++);

    stampa_lista_doppiamente_concatenata_testa(testa);
}