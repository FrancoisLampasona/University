#include <stdio.h>
#include "queue.h"

int main(void)
{
    Queue *struttura = createQueue();
    enqueue(struttura, 10);
    enqueue(struttura, 20);
    enqueue(struttura, 30);
    enqueue(struttura, 40);
    printQueue(struttura);

    printf("Rimozione: %d\n", dequeue(struttura));
    printf("Rimozione: %d\n", dequeue(struttura));

    printf("Coda dopo la rimozione: ");
    printQueue(struttura);

    return 0;
}