#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct dipendente
{
    char *nome;
    char *id;
} Dipendente;

typedef struct cliente
{
    char *nome;
    struct cliente *next;
} Cliente;

typedef struct cassa
{
    Dipendente *impiegato;
    Cliente *primo;
    Cliente *ultimo;
} Cassa;

void enqueue(Cassa **new_cassa, char *nome_cliente)
{

    Cliente *new_cliente = (Cliente *)malloc(sizeof(Cliente));
    new_cliente->nome = strdup(nome_cliente);
    new_cliente->next = NULL;

    if (!(*new_cassa)->primo)
    {
        (*new_cassa)->primo = new_cliente;
        (*new_cassa)->ultimo = new_cliente;
    }
    else
    {
        (*new_cassa)->ultimo->next = new_cliente;
        (*new_cassa)->ultimo = new_cliente;
    }
}

char *dequeue(Cassa **new_cassa)
{
    if ((*new_cassa) == NULL || (*new_cassa)->primo == NULL)
    {
        printf("Coda vuota!\n");
        return NULL;
    }

    Cassa *visualizzatore = *new_cassa;
    char *nome = visualizzatore->primo->nome;
    Cliente *uscente = visualizzatore->primo;
    visualizzatore->primo = visualizzatore->primo->next;

    if (visualizzatore->primo == NULL)
    {
        visualizzatore->ultimo = NULL;
    }

    free(uscente);
    return nome;
}

void print_queue(Cassa *new_cassa)
{
    Cliente *current = new_cassa->primo;
    while (current != NULL)
    {
        printf("%s ", current->nome);
        current = current->next;
    }
    printf("\n");
}

int main(int argc, const char *argv[])
{
    // if (!argc)
    // {
    //     printf("Errore passaggio parametri");
    //     exit(1);
    // }

    // FILE *fp = fopen(argv[1], "w+");

    // if (!fp)
    // {
    //     printf("Errore apertura file");
    //     exit(2);
    // }

    int k = 5;

    Cassa *cassa_array[4];
    for (int i = 0; i < 4; i++)
    {
        cassa_array[i] = (Cassa *)malloc(sizeof(Cassa));
        if (!cassa_array[i])
        {
            perror("Errore allocazione memoria");
            exit(3);
        }
        cassa_array[i]->impiegato = NULL;
        cassa_array[i]->primo = NULL;
        cassa_array[i]->ultimo = NULL;
        for (int j = 0; j < k; j++)
        {
            enqueue(&cassa_array[i], "Mario");
        }
        k--;
    }

    print_queue(cassa_array[1]);
}