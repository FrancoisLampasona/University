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
        stringa[strcspn(stringa, "\n")] = '\0'; // Rimuove il carattere di nuova linea

        int indice = (int)stringa[0];

        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        if (!new_node)
        {
            printf("Errore allocazione dinamica memoria\n");
            exit(1);
        }

        new_node->s = strdup(stringa);
        new_node->next = NULL;

        if (!V[indice])
        {
            V[indice] = new_node;
        }
        else
        {
            struct node *tmp = V[indice];
            struct node *prev = NULL;

            while (tmp != NULL && strcmp(tmp->s, stringa) < 0)
            {
                prev = tmp;
                tmp = tmp->next;
            }

            if (prev == NULL)
            {
                new_node->next = V[indice];
                V[indice] = new_node;
            }
            else
            {
                prev->next = new_node;
                new_node->next = tmp;
            }
        }
    }
}

void mediano(struct node **V, char c)
{
    int indice = (int)c;
    struct node *slow = V[indice];
    struct node *fast = V[indice];

    if (!slow)
    {
        printf("Lista vuota per il carattere %c\n", c);
        return;
    }

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("Il mediano per il carattere %c: %s\n", c, slow->s);
}

void stampa(struct node **V, char c)
{
    int indice = (int)c;
    struct node *current = V[indice];

    if (!current)
    {
        printf("Lista vuota per il carattere %c\n", c);
        return;
    }

    printf("Lista per il carattere %c:\n", c);
    while (current != NULL)
    {
        printf("%s\n", current->s);
        current = current->next;
    }
}

int main(void)
{
    struct node *V[256] = {NULL}; // Inizializzazione dell'array di puntatori

    FILE *fp = fopen("testo.txt", "r");

    if (!fp)
    {
        printf("Errore apertura file\n");
        return 0;
    }

    crea_array_list(V, fp);
    fclose(fp); // Chiude il file dopo la lettura

    mediano(V, 'c');
    stampa(V, 'c');

    return 0;
}
