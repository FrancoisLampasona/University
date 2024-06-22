#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    int num;
    struct tree *right;
    struct tree *left;
} NodeTree;

NodeTree *crea_nodo(NodeTree *root, int num)
{
    if (root == NULL)
    {
        NodeTree *new_node = (NodeTree *)malloc(sizeof(NodeTree));
        if (!new_node)
        {
            printf("Errore allocazione memoria\n");
            exit(1);
        }
        new_node->num = num;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }

    if (num < root->num)
    {
        root->left = crea_nodo(root->left, num);
    }
    else if (num > root->num)
    {
        root->right = crea_nodo(root->right, num);
    }

    return root;
}

void visit_preorder(NodeTree *root)
{
    if (root)
    {
        printf("%d ", root->num);
        visit_preorder(root->left);
        visit_preorder(root->right);
    }
}

int contafoglie(NodeTree *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    return conta_foglie(root->left) + conta_foglie(root->right);
}

int main(void)
{
    NodeTree *root = NULL;
    root = crea_nodo(root, 8);
    crea_nodo(root, 3);
    crea_nodo(root, 10);
    crea_nodo(root, 1);
    crea_nodo(root, 6);
    crea_nodo(root, 14);
    crea_nodo(root, 13);
    crea_nodo(root, 4);
    crea_nodo(root, 7);

    visit_preorder(root);
    return 0;
}
