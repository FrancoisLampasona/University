#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode
{
    int value;
    struct treeNode *sinistro;
    struct treeNode *destro;
} TreeNode;

TreeNode *create_node(int value)
{
    TreeNode *new_node = (TreeNode *)malloc(sizeof(TreeNode));
    if (!new_node)
    {
        printf("Errore allocazione memoria\n");
        exit(1);
    }
    new_node->value = value;
    new_node->sinistro = NULL;
    new_node->destro = NULL;

    return new_node;
}

TreeNode *new_tree(TreeNode *root, int value)
{
    if (!root)
    {
        root = create_node(value);
        return root;
    }

    if (value < root->value)
    {
        root->sinistro = new_tree(root->sinistro, value);
    }
    else
    {
        root->destro = new_tree(root->destro, value);
    }
    return root;
}

void inOrderTraversal(TreeNode *root)
{
    if (root)
    {
        inOrderTraversal(root->sinistro);
        printf("%d ", root->value);
        inOrderTraversal(root->destro);
    }
}

int conta_foglie(TreeNode *root)
{
    if (root == NULL)
    {
        return 0; // No leaf in an empty tree
    }
    if (root->sinistro == NULL && root->destro == NULL)
    {
        return 1; // This node is a leaf
    }
    return conta_foglie(root->sinistro) + conta_foglie(root->destro);
}

int altezza_albero(TreeNode *root)
{
    if (root == NULL)
        return -1; // Altezza di un albero vuoto è -1

    int altezzaSinistra = altezza_albero(root->sinistro);
    int altezzaDestra = altezza_albero(root->destro);

    // Restituisce l'altezza massima tra il sottoalbero sinistro e quello destro
    return 1 + (altezzaSinistra > altezzaDestra ? altezzaSinistra : altezzaDestra);
}

int main(void)
{
    TreeNode *root = NULL;
    root = new_tree(root, 15);
    new_tree(root, 1);
    new_tree(root, 32);
    new_tree(root, 16);
    new_tree(root, 6);
    new_tree(root, 3);
    new_tree(root, 8);
    new_tree(root, 7);
    new_tree(root, 9);
    new_tree(root, 10);

    printf("Traversale in ordine: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Ci sono %d foglie nell'albero \n", conta_foglie(root));
    printf("L'altezza dell'albero e' %d\n", altezza_albero(root));

    return 0;
}
