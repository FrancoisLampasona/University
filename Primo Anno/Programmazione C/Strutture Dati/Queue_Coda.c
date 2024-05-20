#include <stdio.h>
#include <stdlib.h>

// Queue (Code) sono una struttura dati First In First Out (FIFO)
// L'ordine di inserimento coincide con l'ordine di rimozione
// Gli elementi sono inseriti in coda (enqueue) e rimossi dalla testa (dequeue)

typedef struct Queue_Coda
{
    int valore;
    struct queueNode *next;
} QueueNode;

// Funzione per aggiungere un elemento alla coda (enqueue)
void enqueue(QueueNode **head, QueueNode **tail, int valore)
{
    QueueNode *new_node = (QueueNode *)malloc(sizeof(QueueNode));
    if (!new_node)
    {
        printf("Errore allocazione della memoria\n");
        exit(1);
    }
    new_node->valore = valore;
    new_node->next = NULL;

    if (*tail == NULL)
    {
        *head = new_node;
        *tail = new_node;
    }
    else
    {
        (*tail)->next = new_node;
        *tail = new_node;
    }
}

// Funzione per rimuovere un elemento dalla coda (dequeue)
int dequeue(QueueNode **head, QueueNode **tail)
{

    if (*head == NULL)
    {
        printf("La coda è vuota\n");
        return -1;
    }

    QueueNode *tmp = *head;
    int valore = tmp->valore;
    *head = (*head)->next;

    if (*head == NULL)
    {
        *tail = NULL;
    }

    free(tmp);
    return valore;
}

// Funzione per stampare gli elementi della coda
void printQueue(QueueNode *head)
{
    QueueNode *current = head;
    while (current != NULL)
    {
        printf("%d ", current->valore);
        current = current->next;
    }
    printf("\n");
}

int main(void)
{
    QueueNode *head = NULL;
    QueueNode *tail = NULL;

    enqueue(&head, &tail, 10);
    enqueue(&head, &tail, 20);
    enqueue(&head, &tail, 30);
    enqueue(&head, &tail, 40);

    printf("Coda: ");
    printQueue(head);

    printf("Elemento rimosso: %d\n", dequeue(&head, &tail));
    printf("Elemento rimosso: %d\n", dequeue(&head, &tail));

    printf("Coda dopo dequeue: ");
    printQueue(head);

    return 0;
}
