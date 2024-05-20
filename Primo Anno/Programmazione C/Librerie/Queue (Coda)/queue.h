#ifndef queue_h
#define queue_h

typedef struct queue_nodo
{
    int valore;
    struct queue_nodo *next;
} Nodo;

typedef struct queue_struttura
{
    Nodo *head;
    Nodo *tail;
} Queue;

// Funzione per creare una coda vuota
Queue *createQueue();

// Funzione per creare un nuovo nodo
Nodo *newNodo(int k);

// Funzione per aggiungere un elemento alla coda
void enqueue(Queue *struttura, int valore);

// Funzione per eliminare/estrarre un elemento alla coda
int dequeue(Queue *struttura);

// Funzione per stampare gli elementi della coda
void printQueue(Queue *struttura);

#endif