#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Albero_Binario
{
    int valore;
    struct Albero_Binario *right;
    struct Albero_Binario *left;
} Nodo;

// Funzione per creare un nuovo nodo
Nodo *createNodo(int valore)
{
    Nodo *newNodo = (Nodo *)malloc(sizeof(Nodo));
    if (!newNodo)
    {
        printf("Errore nella allocazione di memoria.\n");
        exit(EXIT_FAILURE);
    }
    newNodo->valore = valore;
    newNodo->left = NULL;
    newNodo->right = NULL;
    return newNodo;
}

// Funzione per inserire un nodo in un albero binario di ricerca
Nodo *insertNodo(Nodo *root, int valore)
{
    if (root == NULL)
    {
        root = createNodo(valore);
        return root;
    }

    if (valore < root->valore)
    {
        root->left = insertNodo(root->left, valore);
    }
    else
    {
        root->right = insertNodo(root->right, valore);
    }

    return root;
}

// Funzione per la traversale in ordine
void inOrderTraversal(Nodo *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->valore);
        inOrderTraversal(root->right);
    }
}

// Funzione per la traversale pre-ordine
void preOrderTraversal(Nodo *root)
{
    if (root != NULL)
    {
        printf("%d ", root->valore);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Funzione per la traversale post-ordine
void postOrderTraversal(Nodo *root)
{
    if (root != NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->valore);
    }
}

void print_sottoalbero(Nodo *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->valore);
    print_sottoalbero(root->left);
    print_sottoalbero(root->right);
    printf("\n");
}

void print_albero(Nodo *root)
{
    if (root == NULL)
    {
        printf("Non ci sono nodi nell'albero \n");
        return;
    }

    printf("Radice : %d\n", root->valore);

    printf("Sottoalbero sinistro: \n");
    print_sottoalbero(root->left);

    printf("Sottoalbero destro: \n");
    print_sottoalbero(root->right);
}

// Funzione per deallocare l'intero albero
void deallocateTree(Nodo *root)
{
    if (root == NULL)
        return;

    deallocateTree(root->left);
    deallocateTree(root->right);
    free(root);
}

int main()
{
    Nodo *root = NULL;
    root = insertNodo(root, 10);
    insertNodo(root, 7);
    insertNodo(root, 3);
    insertNodo(root, 9);
    insertNodo(root, 12);
    insertNodo(root, 20);
    insertNodo(root, 11);

    // Il nodo padre dopo il sotto albero di sinistra ma prima di quello di destra
    printf("Traversale in ordine: ");
    inOrderTraversal(root);
    printf("\n");

    // Il nodo padre prima di tutti i figli
    printf("Traversale pre-ordine: ");
    preOrderTraversal(root);
    printf("\n");

    // Il nodo padre dopo tutti i figli
    printf("Traversale post-ordine: ");
    postOrderTraversal(root);
    printf("\n\n");

    print_albero(root);

    // Dealloca l'intero albero
    deallocateTree(root);

    return 0;
}
