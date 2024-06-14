#include <stdio.h>
#include <stdlib.h>

typedef struct Tree
{
    int num;
    struct Tree *right;
    struct Tree *left;
} NodeTree;

typedef struct queue
{
    NodeTree *node;
    struct queue *next;
} NodeQueue;

NodeTree *inserisci_nodo(NodeTree *p, int i)
{
    if (!p)
    {
        NodeTree *new_node = (NodeTree *)malloc(sizeof(NodeTree));
        if (!new_node)
        {
            printf("Errore allocazione memoria\n");
            exit(1);
        }

        new_node->num = i;
        new_node->right = NULL;
        new_node->left = NULL;
        return new_node;
    }

    if (i < p->num)
    {
        p->left = inserisci_nodo(p->left, i);
    }
    else if (i > p->num)
    {
        p->right = inserisci_nodo(p->right, i);
    }

    return p;
}

void inOrderTraversal(NodeTree *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->num);
        inOrderTraversal(root->right);
    }
}

void enqueue_coda(NodeQueue **head, NodeQueue **tail, NodeTree *p)
{
    NodeQueue *new_node = (NodeQueue *)malloc(sizeof(NodeQueue));
    if (!new_node)
    {
        printf("Errore allocazione della memoria\n");
        exit(1);
    }
    new_node->node = p;
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

NodeTree *dequeue_coda(NodeQueue **head, NodeQueue **tail)
{
    if (*head == NULL)
        return NULL;

    NodeQueue *temp = *head;
    *head = (*head)->next;
    if (*head == NULL)
        *tail = NULL;

    NodeTree *node = temp->node;
    free(temp);
    return node;
}

void bfs(NodeTree *root)
{
    if (root == NULL)
        return;

    NodeQueue *head = NULL;
    NodeQueue *tail = NULL;

    enqueue_coda(&head, &tail, root);

    while (head != NULL)
    {
        NodeTree *current = dequeue_coda(&head, &tail);
        printf("%d ", current->num);

        if (current->left != NULL)
            enqueue_coda(&head, &tail, current->left);
        if (current->right != NULL)
            enqueue_coda(&head, &tail, current->right);
    }
}

int main(void)
{
    NodeTree *root = NULL;
    root = inserisci_nodo(root, 40);
    inserisci_nodo(root, 12);
    inserisci_nodo(root, 62);
    inserisci_nodo(root, 55);
    inserisci_nodo(root, 67);
    inserisci_nodo(root, 60);
    inserisci_nodo(root, 63);
    inserisci_nodo(root, 70);
    inOrderTraversal(root);

    printf("\nVisita in ampiezza (BFS):\n");
    bfs(root);
    printf("\n");

    return 0;
}
