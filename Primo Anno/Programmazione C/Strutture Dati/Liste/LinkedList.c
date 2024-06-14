#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int valore;
    struct node *next;
} Nodo;

// Inserimento in testa di un nodo 2 -> 1 diventa "(New_nodo) -> 2 -> 1"
Nodo *inserimento_in_testa(int valore, Nodo *p)
{
    Nodo *new_node = (Nodo *)malloc(sizeof(Nodo));

    if (new_node == NULL)
    {
        printf("Errore: Allocazione memoria\n");
        exit(1);
    }

    new_node->valore = valore;
    new_node->next = p;
    return new_node;
}

// Inserimento in coda di un nodo 1 -> 2 diventa "1 -> 2 -> (New_nodo)"
Nodo *inserimento_in_coda(int valore, Nodo *p)
{
    Nodo *new_node = (Nodo *)malloc(sizeof(Nodo));

    if (new_node == NULL)
    {
        printf("Errore: Allocazione memoria\n");
        exit(2);
    }

    new_node->valore = valore;
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

// Inserimento In Coda Ricorsivamente
Nodo *inserimento_in_coda_ricorsivo(int valore, Nodo *p)
{
    if (p == NULL)
    {
        Nodo *new_node = (Nodo *)malloc(sizeof(Nodo));
        if (new_node == NULL)
        {
            printf("Errore: Allocazione memoria\n");
            exit(2);
        }
        new_node->valore = valore;
        new_node->next = NULL;
        return new_node;
    }
    else
    {
        p->next = inserimento_in_coda_ricorsivo(valore, p->next);
        return p;
    }
}

// Ricerca Di Un Valore
Nodo *ricerca_valore(int valore, Nodo *p)
{
    while (p != NULL)
    {
        if (p->valore == valore)
        {
            return p;
        }
        p = p->next;
    }
    printf("Valore non presente\n");
    return NULL;
}

// Ricerca Di Un Valore Ricorsivamente
Nodo *ricerca_valore_ricorsivo(int valore, Nodo *p)
{

    if (p == NULL)
    {
        printf("Valore non presente\n");
        return NULL;
    }
    else if (p->valore == valore)
    {
        return p;
    }
    else
    {
        return ricerca_valore(valore, p->next);
    }
}

// Rimozione Di Un Nodo
Nodo *rimozione_nodo(int valore, Nodo *p)
{

    if (p == NULL)
    {
        printf("Non ci sono nodi\n");
        return NULL;
    }

    Nodo *corrente = p;
    Nodo *precedente = NULL;

    while (corrente != NULL)
    {
        if (corrente->valore == valore)
        {
            if (precedente == NULL)
            {
                p = corrente->next;
            }
            else
            {
                precedente->next = corrente->next;
            }
            free(corrente);
            return p;
        }
        precedente = corrente;
        corrente = corrente->next;
    }
    return p;
}

// Rimozione Di Un Nodo Ricorsivamente
Nodo *rimozione_nodo_ricorsivo(int valore, Nodo *p)
{

    if (p == NULL)
    {
        printf("Non ci sono nodi\n");
        return NULL;
    }

    if (p->valore == valore)
    {
        Nodo *temp = p;
        p = p->next;
        free(temp);
        return p;
    }
    else
    {
        p->next = rimozione_nodo_ricorsivo(valore, p->next);
        return p;
    }
}

// Elimina Lista
Nodo *distruggi_lista(Nodo *p)
{
    Nodo *corrente = p;
    Nodo *successivo = NULL;

    while (p != NULL)
    {
        successivo = corrente->next;
        free(corrente);
        corrente = successivo;
    }
    return NULL;
}

// Elimina Lista Ricorsivamente
Nodo *distruggi_lista_ricorsivo(Nodo *p)
{
    if (p != NULL)
    {
        distruggi_lista_ricorsivo(p->next);
        free(p);
    }
    return NULL;
}

// Stampa Lista
void stampa_lista(Nodo *p)
{
    if (p == NULL)
    {
        printf("Lista vuota\n");
        return;
    }
    while (p != NULL)
    {
        printf(" %d ->", p->valore);
        p = p->next;
    }
    printf(" NULL \n");
}

// Stampa Lista Ricorsivamente
void stampa_lista_ricorsivo(Nodo *p)
{
    if (p == NULL)
    {
        printf("Lista vuota\n");
        return;
    }
    printf(" %d ->", p->valore);
    stampa_lista_ricorsiva(p->next);
    printf(" NULL \n");
}

// Concatena Due Liste p1 + p2
Nodo *concatenare_liste(Nodo *p1, Nodo *p2)
{
    if (p1 == NULL)
    {
        return p2;
    }
    else
    {
        Nodo *corrente = p1;
        while (corrente->next != NULL)
        {
            corrente = corrente->next;
        }
        corrente->next = p2;
        return p1;
    }
}

// Concatena Due Liste p1 + p2 Ricorsivamente
Nodo *concatenare_liste_ricorsiva(Nodo *p1, Nodo *p2)
{
    if (p1 == NULL)
    {
        return p2;
    }
    else
    {
        p1->next = concatenare_liste_ricorsiva(p1->next, p2);
        return p1;
    }
}

// Merge Di Due Liste Ordinate
Nodo *merge_liste_ordinate(Nodo *p1, Nodo *p2)
{
    Nodo *corrente = NULL;
    Nodo *head = NULL;

    if (p1 == NULL)
    {
        return p2;
    }
    else if (p2 == NULL)
    {
        return p1;
    }

    if (p1->valore <= p2->valore)
    {
        corrente = p1;
        p1 = p1->next;
    }
    else
    {
        corrente = p2;
        p2 = p2->next;
    }

    head = corrente;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->valore <= p2->valore)
        {
            corrente->next = p1;
            corrente = p1;
            p1 = p1->next;
        }
        else
        {
            corrente->next = p2;
            corrente = p2;
            p2 = p2->next;
        }
    }

    if (p1 != NULL)
    {
        corrente->next = p1;
    }
    else
    {
        corrente->next = p2;
    }
    return head;
}

// Merge Di Due Liste Ordinate Ricorsivamente
Nodo *merge_liste_ordinate_ricorsivo(Nodo *p1, Nodo *p2)
{
    Nodo *corrente = NULL;

    if (p1 == NULL)
    {
        return p2;
    }
    else if (p2 == NULL)
    {
        return p1;
    }

    if (p1->valore <= p2->valore)
    {
        corrente = p1;
        corrente->next = merge_liste_ordinate_ricorsivo(p1->next, p2);
    }
    else
    {
        corrente = p2;
        corrente->next = merge_liste_ordinate_ricorsivo(p1, p2->next);
    }
    return corrente;
}

int main(void)
{
    printf("Lista semplicemente concatenata \n");

    Nodo *lista_1 = NULL;
    Nodo *lista_2 = NULL;
    Nodo *prove = NULL;
    int valore = 1;

    lista_1 = inserimento_in_coda(valore++, lista_1);
    lista_1 = inserimento_in_coda(valore++, lista_1);
    lista_1 = inserimento_in_coda(valore++, lista_1);
    lista_1 = inserimento_in_coda(valore++, lista_1);
    lista_1 = inserimento_in_coda(valore++, lista_1);

    lista_2 = inserimento_in_coda(valore++, lista_2);
    lista_2 = inserimento_in_coda(valore++, lista_2);
    lista_2 = inserimento_in_coda(valore++, lista_2);
    lista_2 = inserimento_in_coda(valore++, lista_2);
    lista_2 = inserimento_in_coda(valore++, lista_2);

    prove = merge_liste_ordinate(lista_1, lista_2);
    stampa_lista(prove);
}
