#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// Funzione per creare una coda vuota
Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->head = q->tail = NULL;
    return q;
}

// Funzione per creare un nuovo nodo
Nodo *create_new_nodo(int k)
{
    Nodo *temp = (Nodo *)malloc(sizeof(Nodo));
    if (!temp)
    {
        printf("Errore nel allocazione della memoria\n");
        exit(1);
    }

    temp->valore = k;
    temp->next = NULL;
    return temp;
}

// Funzione per aggiungere un elemento alla coda
void enqueue(Queue *struttura, int valore)
{
    Nodo *new_nodo = create_new_nodo(valore);
    if (struttura->tail == NULL)
    {
        struttura->head = new_nodo;
        struttura->tail = new_nodo;
        return;
    }
    struttura->tail->next = new_nodo;
    struttura->tail = new_nodo;
}

// Funzione per eliminare/estrarre un elemento alla coda
int dequeue(Queue *struttura)
{
    if (struttura->head == NULL)
    {
        printf("La coda è vuota\n");
        return -1;
    }

    Nodo *tmp = struttura->head;
    int data = tmp->valore;
    struttura->head = struttura->head->next;
    free(tmp);
    if (struttura->head == NULL)
    {
        struttura->tail = NULL;
    }
    return data;
}

// Funzione per stampare gli elementi della coda
void printQueue(Queue *struttura)
{
    if (struttura->head == NULL)
    {
        printf("La coda è vuota\n");
        return;
    }

    Nodo *current = struttura->head;
    printf("Coda: ");
    while (current != NULL)
    {
        printf("%d ", current->valore);
        current = current->next;
    }
    printf("\n");
}