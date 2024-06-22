#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    void *pv;
    char tipo;
    struct node *next;
};

void crea_lista(struct node **p, FILE *fd)
{
    char tipo;
    char stringa[256];
    int intero;
    double doppio_num;

    while (fgets(stringa, sizeof(stringa), fd))
    {

        if (sscanf(stringa, "%c %s", &tipo, stringa) == 2)
        {
            struct node *new_node = (struct node *)malloc(sizeof(struct node));
            if (!new_node)
            {
                printf("Errore allocazione memoria\n");
                exit(1);
            }

            new_node->tipo = tipo;
            new_node->next = NULL;

            printf("%c ", tipo);

            if (tipo == '0')
            {
                sscanf(stringa, "%d", &intero);
                new_node->pv = (int *)malloc(sizeof(int));
                if (!new_node)
                {
                    printf("Errore allocazione memoria\n");
                    exit(2);
                }
                *(int *)new_node->pv = intero;
                printf("%d\n", *(int *)new_node->pv);
            }
            else if (tipo == '1')
            {
                sscanf(stringa, "%lf", &doppio_num);
                new_node->pv = (double *)malloc(sizeof(double));
                if (!new_node)
                {
                    printf("Errore allocazione memoria\n");
                    exit(3);
                }
                *(double *)new_node->pv = doppio_num;
                printf("%lf \n", *(double *)new_node->pv);
            }
            else if (tipo == '2')
            {
                new_node->pv = (char *)malloc(sizeof(char) * strlen(stringa) + 1);
                if (!new_node)
                {
                    printf("Errore allocazione memoria\n");
                    exit(4);
                }
                strcpy((char *)new_node->pv, stringa);
                printf("%s \n", new_node->pv);
            }

            if (!(*p))
            {
                *p = new_node;
            }
            else
            {
                struct node *tmp = *p;
                while (tmp->next)
                {
                    tmp = tmp->next;
                }
                tmp->next = new_node;
            }
        }
    }
}

void inserisci_ordianto(struct node *v[3], struct node *p)
{
    while (p)
    {
        if (p->tipo == '0')
        {
            struct node *new_node_0 = (struct node *)malloc(sizeof(struct node));
            if (!new_node_0)
            {
                printf("Errore allocazione memoria\n");
                exit(5);
            }
            new_node_0->next = NULL;
            new_node_0->tipo = p->tipo;
            new_node_0->pv = p->pv;

            if (v[0] == NULL)
            {
                struct node *tmp = v[0];
                while (tmp->next)
                {
                    tmp = tmp->next;
                }
                tmp->next = new_node_0;
            }
        }
        else if (p->tipo == '1')
        {
            struct node *new_node_1 = (struct node *)malloc(sizeof(struct node));
            if (!new_node_1)
            {
                printf("Errore allocazione memoria\n");
                exit(6);
            }
            new_node_1->next = NULL;
            new_node_1->tipo = p->tipo;
            new_node_1->pv = p->pv;

            if (v[1] == NULL)
            {
                struct node *tmp = v[1];
                while (tmp->next)
                {
                    tmp = tmp->next;
                }
                tmp->next = new_node_1;
            }
        }
        else if (p->tipo == '2')
        {
            struct node *new_node_2 = (struct node *)malloc(sizeof(struct node));
            if (!new_node_2)
            {
                printf("Errore allocazione memoria\n");
                exit(7);
            }
            new_node_2->next = NULL;
            new_node_2->tipo = p->tipo;
            new_node_2->pv = p->pv;

            if (v[2] == NULL)
            {
                struct node *tmp = v[2];
                while (tmp->next)
                {
                    tmp = tmp->next;
                }
                tmp->next = new_node_2;
            }
        }
    }
}

void print_list(struct node *testa)
{
    if (!testa)
    {
        printf("NULL\n");
        return;
    }
    if (testa->tipo == '1')
    {
        printf("%d -> ", *(int *)testa->pv);
    }
    else if (testa->tipo == '1')
    {
        printf("%lf -> ", *(double *)testa->pv);
    }
    else if (testa->tipo == '2')
    {
        printf("%s -> ", (char *)testa->pv);
    }
    print_list(testa->next);
}

int main(void)
{

    FILE *fp = fopen("testo_file_1.txt", "r");
    if (!fp)
    {
        printf("Errore apertura file\n");
        return 1;
    }

    struct node *testa = NULL;
    struct node *testa_separate[3];
    testa_separate[0] = NULL;
    testa_separate[1] = NULL;
    testa_separate[2] = NULL;

    crea_lista(&testa, fp);
    print_list(testa);

    inserisci_ordianto(&testa_separate[3], testa);
    print_list(testa_separate[0]);
}
