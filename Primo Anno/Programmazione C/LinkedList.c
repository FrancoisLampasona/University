#include <stdio.h>
#include <stdlib.h>

// Definizione della struttura del nodo
struct Nodo {
    int valore;
    struct Nodo* successivo;
};

// Definizione della struttura della lista concatenata
struct ListaConcatenata {
    struct Nodo* testa;
    struct Nodo* coda;
};

// Funzione per inserire un nuovo nodo in coda alla lista concatenata
void inserisci_in_coda(struct ListaConcatenata* lista, int valore) {
    // Creazione del nuovo nodo
    struct Nodo* nuovo_nodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuovo_nodo->valore = valore;
    nuovo_nodo->successivo = NULL;

    // Se la lista è vuota, il nuovo nodo diventa sia la testa che la coda
    if (lista->coda == NULL) {
        lista->testa = nuovo_nodo;
    } else {
        // Altrimenti, collega il nuovo nodo alla coda attuale
        lista->coda->successivo = nuovo_nodo;
    }

    // Aggiorna il riferimento alla coda per puntare al nuovo nodo
    lista->coda = nuovo_nodo;
}

// Funzione per stampare la lista concatenata
void stampa_lista(struct ListaConcatenata* lista) {
    struct Nodo* nodo_corrente = lista->testa;
    while (nodo_corrente != NULL) {
        printf("%d -> ", nodo_corrente->valore);
        nodo_corrente = nodo_corrente->successivo;
    }
    printf("NULL\n");
}

// Funzione principale
int main() {
    struct ListaConcatenata lista;
    lista.testa = NULL;
    lista.coda = NULL;
    
    int valore;
    printf("Inserisci una sequenza di interi positivi (termina con un numero negativo):\n");
    while (1) {
        scanf("%d", &valore);
        if (valore < 0) {
            break;
        }
        inserisci_in_coda(&lista, valore);
    }

    printf("Lista concatenata:\n");
    stampa_lista(&lista);

    return 0;
}
