#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Un puntatore è una variabile/tipo di dato che memorizza l'indirizzo di memoria di un'altra variabile come valore.
// Una variabile puntatore punta a un tipo di dati (come int) dello stesso tipo e viene creata con l'operatore *.

// Definizione di una struttura per rappresentare una persona
struct Persona
{
    char nome[20];
    int eta;
};

// Funzione di esempio che prende un puntatore a int come argomento e lo modifica
void modificaInt(int *valore)
{
    *valore = 20; // Modifica il valore puntato dal puntatore
}

// Funzione di esempio che prende un puntatore a char e stampa la stringa
void stampaStringa(char *str)
{
    printf("Stringa: %s\n", str); // Stampa la stringa puntata dal puntatore
}

int main()
{
    // Esempio di puntatore a una variabile intera
    int a = 10;
    int *ptr_a = &a; // Dichiarazione e inizializzazione di un puntatore a int che punta a 'a'

    // Stampa dei valori
    printf("Valore di a: %d\n", a);                  // Stampa il valore di 'a'
    printf("Valore puntato da ptr_a: %d\n", *ptr_a); // Stampa il valore puntato dal puntatore

    // Modifica il valore di 'a' tramite il puntatore
    *ptr_a = 15;                          // Modifica il valore puntato da 'ptr_a' a 15
    printf("Nuovo valore di a: %d\n", a); // Stampa il nuovo valore di 'a'

    // Esempio di puntatore a una funzione
    void (*funzione_ptr)(char *);  // Dichiarazione di un puntatore a funzione che prende un puntatore a char come argomento
    funzione_ptr = &stampaStringa; // Assegnazione del puntatore alla funzione 'stampaStringa'

    // Chiamata alla funzione attraverso il puntatore
    (*funzione_ptr)("Ciao, sono una stringa!"); // Chiamata alla funzione puntata da 'funzione_ptr'

    // Esempio di puntatore a una struttura
    struct Persona persona1;                 // Dichiarazione di una variabile di tipo 'Persona'
    struct Persona *ptr_persona = &persona1; // Dichiarazione di un puntatore a 'Persona' che punta a 'persona1'

    // Assegnazione dei valori alla struttura attraverso il puntatore
    strcpy(ptr_persona->nome, "Mario"); // Copia la stringa "Mario" nel campo 'nome' della struttura puntata
    ptr_persona->eta = 30;              // Assegna il valore 30 al campo 'eta' della struttura puntata

    // Stampa dei valori della struttura attraverso il puntatore
    printf("Nome: %s, Eta': %d\n", ptr_persona->nome, ptr_persona->eta);

    // Esempio di allocazione dinamica della memoria per un array
    int *array_dinamico = (int *)malloc(5 * sizeof(int)); // Alloca memoria per un array di 5 interi

    // Verifica se l'allocazione della memoria è avvenuta con successo
    if (array_dinamico == NULL)
    {
        printf("Errore: impossibile allocare la memoria.\n");
        return 1; // Termina il programma con un codice di errore
    }

    // Inizializzazione dell'array dinamico
    for (int i = 0; i < 5; i++)
    {
        array_dinamico[i] = i * 2; // Assegna i valori 0, 2, 4, 6, 8 all'array
    }

    // Stampa degli elementi dell'array dinamico
    printf("Elementi dell'array dinamico:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", array_dinamico[i]); // Stampa l'i-esimo elemento dell'array dinamico
    }
    printf("\n");

    // Liberazione della memoria allocata dinamicamente
    free(array_dinamico);

    // Esempio di passaggio di puntatori a funzioni
    int valore = 10;
    printf("Valore prima della modifica: %d\n", valore);
    modificaInt(&valore); // Passa l'indirizzo di memoria di 'valore' alla funzione 'modificaInt'
    printf("Valore dopo la modifica: %d\n", valore);

    return 0; // Termina il programma con successo
}
