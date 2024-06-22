#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char *s;
    struct node *next;
};

void crea_array_list(struct node **V, FILE *fp)
{
    char stringa[256];

    while (fgets(stringa, sizeof(stringa), fp))
    {
        stringa[sizeof(stringa) - 1] = '\0';

        int indice = (int)stringa[0];

        struct node *new_node = (struct node *)malloc(sizeof(struct node *));
        if (new_node)
        {
            printf("Errore allocazione dinamica memeoria\n");
            exit(1);
        }

        new_node->next = NULL;
        new_node->s = strdup(stringa);

        if (!V[indice])
        {
            V[indice] = new_node;
        }
        else
        {
            struct node *tmp = V[indice];

            while (tmp != NULL && strcmp(tmp->s, stringa) < 0)
            {
                
            }
        }

        printf("%d ", indice);
    }
}

void mediano(struct node **V, char c)
{
}

void stampa(struct node **V, char c)
{
}

int main(void)
{
    struct node *V[256];

    FILE *fp = fopen("testo.txt", "r");

    if (!fp)
    {
        printf("Errore apertura file\n");
        return 0;
    }

    crea_array_list(V, fp);
    mediano(V, 'c');
    stampa(V, 'c');
}