#include <stdio.h>
#include <stdlib.h>

typedef struct Stack_Pila
{
    int valore;
    struct Stack_Pila *next;
} StackNode;

void push(StackNode **top, int valore)
{
    StackNode *new_node = (StackNode *)malloc(sizeof(StackNode));
    if (!new_node)
    {
        printf("Errore allocazione di memoria\n");
        exit(1);
    }

    new_node->valore = valore;
    new_node->next = *top;
    *(top) = new_node;
}

int pop(StackNode **top)
{
    if (*top == NULL)
    {
        printf("Non c'e' nessuno in cosa\n");
        return 0;
    }

    StackNode *tmp = (*top);
    *top = (*top)->next;
    int popValue = tmp->valore;
    free(tmp);
    return popValue;
}

int main(void)
{
    StackNode *top;
    for (int i = 0; i < 10; i++)
    {
        push(&top, i + 1);
    }

    printf("%d\n", pop(&top));
    printf("%d\n", pop(&top));
}