// Scrivere una funzione ricorsiva che, ricevuta come argomento una lista concatenata di n caratteri
// dell’alfabeto, restituisca per riferimento in altri due argomenti i punti di accesso destro e sinistro a una
// lista doppiamente concatenata di 2n caratteri dell’alfabeto, che sia simmetrica con inversione maiuscolo/
// minuscolo.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    char lettera;
    struct node *right;
};

struct noded
{
    char lettera;
    struct noded *right;
    struct noded *left;
};

void create_linked_list(struct node **testa, char carattere)
{

    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (!new_node)
    {
        printf("Errore allocazione memoria\n");
        exit(1);
    }
    new_node->lettera = carattere;
    new_node->right = NULL;
    if (!*testa)
    {
        *testa = new_node;
    }
    else
    {
        struct node *tmp = *testa;
        while (tmp->right)
        {
            tmp = tmp->right;
        }
        tmp->right = new_node;
    }
}

void create_double_linked_list(struct noded **testa_doppia, struct node *testa)
{
    struct node *temp = testa;
    struct node *temp_2 = testa;

    while (testa)
    {
        struct noded *new_node = (struct noded *)malloc(sizeof(struct noded));
        if (!new_node)
        {
            printf("Errore allocazione memoria\n");
            exit(1);
        }
        new_node->lettera = testa->lettera;
        new_node->right = NULL;
        new_node->left = NULL;

        if (!*testa_doppia)
        {
            *testa_doppia = new_node;
        }
        else
        {
            struct noded *tmp = *testa_doppia;
            while (tmp->right)
            {
                tmp = tmp->right;
            }
            tmp->right = new_node;
            new_node->left = tmp;
        }
        testa = testa->right;
    }

    while (temp)
    {
        if (islower(temp->lettera))
        {
            temp->lettera = toupper(temp->lettera);
        }
        else
        {
            temp->lettera = tolower(temp->lettera);
        }
        temp = temp->right;
    }

    while (temp_2)
    {
        struct noded *new_node = (struct noded *)malloc(sizeof(struct noded));
        if (!new_node)
        {
            printf("Errore allocazione memoria\n");
            exit(1);
        }
        new_node->lettera = temp_2->lettera;
        new_node->right = NULL;
        new_node->left = NULL;

        if (!*testa_doppia)
        {
            *testa_doppia = new_node;
        }
        else
        {
            struct noded *tmp = *testa_doppia;
            while (tmp->right)
            {
                tmp = tmp->right;
            }
            tmp->right = new_node;
            new_node->left = tmp;
        }
        temp_2 = temp_2->right;
    }
}

void print_list(struct node *testa)
{
    if (testa)
    {
        while (testa)
        {
            printf("%c -> ", testa->lettera);
            testa = testa->right;
        }
        printf("NULL");
    }
}

void print_list_2(struct noded *testa)
{
    if (testa)
    {
        while (testa)
        {
            printf("%c <-> ", testa->lettera);
            testa = testa->right;
        }
        printf("NULL");
    }
}

int main(void)
{

    struct node *testa_linked_list = NULL;
    create_linked_list(&testa_linked_list, 'B');
    create_linked_list(&testa_linked_list, 'a');
    create_linked_list(&testa_linked_list, 'n');
    create_linked_list(&testa_linked_list, 'd');
    create_linked_list(&testa_linked_list, 'B');
    print_list(testa_linked_list);
    struct noded *testa_double_linked_list = NULL;
    create_double_linked_list(&testa_double_linked_list, testa_linked_list);
    printf("\n");
    print_list_2(testa_double_linked_list);
}