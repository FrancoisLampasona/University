#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int info;
    struct nodo *next;
} Nodo;

typedef struct nodoS
{
    struct nodoS *next;
    Nodo *list;
} NodoS;

NodoS *soli12(Nodo *l)
{
    if (!l)
    {
        return NULL;
    }

    NodoS *new_node = (NodoS *)malloc(sizeof(NodoS));
    if (!new_node)
    {
        printf("Errore allocazione memoria\n");
        exit(1);
    }

    Nodo *tmp = l;
    new_node->list = NULL;
    int counter = 0;

    while (counter != 2 && tmp != NULL)
    {
        Nodo *new_element = (Nodo *)malloc(sizeof(Nodo));
        if (new_element == NULL)
        {
            printf("Errore: Allocazione memoria\n");
            exit(2);
        }
        new_element->next = NULL;
        new_element->info = tmp->info;

        if (!new_node->list)
        {
            new_node->list = new_element;
        }
        else
        {
            Nodo *temp = new_node->list;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_element;
        }
        counter++;
        tmp = tmp->next;
    }

    new_node->next = soli12(l->next);

    return new_node;
}

Nodo *inserimento_in_coda(int valore, Nodo *p)
{
    Nodo *new_node = (Nodo *)malloc(sizeof(Nodo));

    if (new_node == NULL)
    {
        printf("Errore: Allocazione memoria\n");
        exit(2);
    }

    new_node->info = valore;
    new_node->next = NULL;

    if (p == NULL)
    {
        return new_node;
    }
    else
    {
        Nodo *temp = p;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    return p;
}

void stampa_lista(Nodo *p)
{
    if (p == NULL)
    {
        printf("Lista vuota\n");
        return;
    }
    while (p != NULL)
    {
        printf(" %d ->", p->info);
        p = p->next;
    }
    printf(" NULL \n");
}

void stampa_listaS(NodoS *p)
{
    if (p == NULL)
    {
        printf("ListaS vuota\n");
        return;
    }
    while (p != NULL)
    {
        printf("Sottolista:\n");
        stampa_lista(p->list);
        p = p->next;
    }
}

int main(void)
{
    Nodo *lista_1 = NULL;
    int valore = 1;
    lista_1 = inserimento_in_coda(valore++, lista_1);
    lista_1 = inserimento_in_coda(valore++, lista_1);
    lista_1 = inserimento_in_coda(valore++, lista_1);
    lista_1 = inserimento_in_coda(valore++, lista_1);
    lista_1 = inserimento_in_coda(valore++, lista_1);

    printf("Lista Orginale :\n");
    stampa_lista(lista_1);

    printf("\nSotto Liste :\n\n");
    NodoS *testa = soli12(lista_1);
    stampa_listaS(testa);

}