#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
    int value;
    struct node *next;
} Node;

void insert_tail(Node **head, int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node)
    {
        printf("Errore allocazione memoria");
        exit(0);
    }
    new_node->value = value;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *(head) = new_node;
    }
    else
    {
        Node *p = *(head);
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = new_node;
    }
}

void stampa_lista(Node *head)
{
    if (head)
    {
        while (head != NULL)
        {
            printf("%d -> ", head->value);
            head = head->next;
        }
        printf("NULL\n");
    }
    else
    {
        printf("Lista vuolta \n");
    }
}

void stampa_ricorsiva(Node *head)
{
    if (!head)
    {
        return;
    }
    printf("%d -> ", head->value);
    stampa_ricorsiva(head->next);
}

void stampa_ricorsiva_inversa(Node *head)
{
    if (!head)
    {
        return;
    }
    stampa_ricorsiva_inversa(head->next);
    printf("%d -> ", head->value);
}

size_t lengthList(Node *p)
{
    int counter = 0;
    while (p != NULL)
    {
        counter++;
        p = p->next;
    }
    return counter;
}

int sumList(Node *p)
{
    int counter = 0;
    while (p != NULL)
    {
        counter += p->value;
        p = p->next;
    }
    return counter;
}

int countList(Node *p, int n)
{

    int furmicula = 0;
    while (p != NULL)
    {
        if (p->value == n)
        {
            furmicula++;
        }
        p = p->next;
    }
    return furmicula;
}

Node *findMax(Node *p)
{
    int max = p->value;
    Node *puntaro_max = NULL;
    p = p->next;
    while (p != NULL)
    {
        if (p->value > max)
        {
            max = p->value;
            puntaro_max = p;
        }
        p = p->next;
    }
    return puntaro_max;
}

Node *copyList(Node *p)
{
    if (!p)
    {
        printf("La prima lista e' vuota\n");
        return NULL;
    }

    Node *head_2 = NULL;
    int lunghezza = lengthList(p);
    for (int i = 0; i < lunghezza; i++)
    {
        insert_tail(&head_2, p->value);
        p = p->next;
    }
    return head_2;
}

Node *copyFromArray(int *a, size_t n)
{
    Node *head_3 = (Node *)malloc(sizeof(Node));

    for (int i = 0; i < n - 1; i++)
    {
        insert_tail(&head_3, a[i]);
    }
    return head_3;
}

int main(void)
{
    Node *head = NULL;
    int *a = (int *)calloc(10, sizeof(int));
    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        a[i] = rand() % 8;
    }

    for (int i = 0; i < 10; i++)
    {
        insert_tail(&head, i);
    }

    printf("La lunghezza della lista e' %d\n", lengthList(head));
    stampa_lista(head);
    stampa_ricorsiva_inversa(head);
    printf("NULL\n");
    printf("La somma degli elementi della lista e' %d\n", sumList(head));
    printf("Il valore 3 e' presente %d volte\n", countList(head, 3));
    Node *ptr_Max = findMax(head);
    printf("Il Max della lista e' %d\n", ptr_Max->value);
    Node *head_2 = copyList(head);
    stampa_lista(head_2);
    Node *head_3 = copyFromArray(a, 10);
    stampa_lista(head_3);
}