#include <stdio.h>
#include <stdlib.h>

struct node
{
    char c;
    struct node *right;
};

struct noder
{
    char c;
    int occ;
    struct noder *right;
};

struct noder *lista_occorenze(struct node *testa)
{

    if (!testa)
    {
        return NULL;
    }

    struct noder *new_node = (struct noder *)malloc(sizeof(struct noder));
    if (!new_node)
    {
        printf("Errore allocazione memoria\n");
        exit(2);
    }

    struct node *tmp = testa;
    int contatore = 1;
    char carattere = testa->c;

    if (tmp->right != NULL)
    {
        tmp = tmp->right;
    }
    else
    {
        return NULL;
    }

    while (tmp != NULL)
    {
        if (tmp->c == carattere)
        {
            contatore++;
        }
        tmp = tmp->right;
    }

    int skip = contatore;

    while (skip > 1)
    {
        testa = testa->right;
        skip--;
    }

    new_node->c = carattere;
    new_node->occ = contatore;
    new_node->right = lista_occorenze(testa->right);

    return new_node;
}

void inserisci_nodi(struct node **testa, char a)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (!new_node)
    {
        printf("Errore allocazione memoria\n");
        exit(1);
    }
    new_node->c = a;
    new_node->right = NULL;

    if (!*testa)
    {
        *testa = new_node;
    }
    else
    {
        struct node *tmp = *testa;
        while (tmp->right != NULL)
        {
            tmp = tmp->right;
        }
        tmp->right = new_node;
    }
}

void printlist(struct node *testa)
{
    if (!testa)
    {
        printf("Lista vuota \n");
        return;
    }
    struct node *tmp = testa;

    while (tmp)
    {
        printf("%c -> ", tmp->c);
        tmp = tmp->right;
    }
    printf("NULL\n");
}

void printlist_occorenze(struct noder *testa)
{
    if (!testa)
    {
        printf("Lista vuota \n");
        return;
    }
    struct noder *tmp = testa;

    while (tmp)
    {
        printf("%c,%d -> ", tmp->c, tmp->occ);
        tmp = tmp->right;
    }
    printf("NULL\n");
}

int main(void)
{
    struct node *testa = NULL;
    inserisci_nodi(&testa, 'a');
    inserisci_nodi(&testa, 'p');
    inserisci_nodi(&testa, 'p');
    inserisci_nodi(&testa, '.');
    inserisci_nodi(&testa, 'i');
    inserisci_nodi(&testa, 'e');
    inserisci_nodi(&testa, 'e');
    inserisci_nodi(&testa, 'e');
    inserisci_nodi(&testa, '7');
    inserisci_nodi(&testa, '6');
    inserisci_nodi(&testa, '6');

    printlist(testa);

    struct noder *testa_occorenze = lista_occorenze(testa);

    printlist_occorenze(testa_occorenze);
}