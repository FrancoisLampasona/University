#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1° Modo di dichiarare le strutture

struct s_libro
{
    char autore[50];
    char titolo[50];
    int pagine;
};

// 2° Modo di dichiarare le strutture

struct s_libro_2
{
    char autore[50];
    char titolo[50];
    int pagine;
} libro_2;

// 3° Modo di dichiarare le strutture (1° + 2°)

struct s_libro_3
{
    char autore[50];
    char titolo[50];
    int pagine;
} libro_3;

// 4° Modo di dichiarare le strutture

struct s_libro_4
{
    char autore[50];
    char titolo[50];
    int pagine;
};

typedef struct s_libro_4 t_libro_4;

// 5° Modo di dichiarare le strutture

typedef struct s_libro_5
{
    char autore[50];
    char titolo[50];
    int pagine;
} t_libro_5;

int main(void)
{

    // Utilizzo 1° dichiarazione di struttura;

    struct s_libro libro;
    strcpy(libro.autore, "Dante");
    strcpy(libro.titolo, "Divina Commedia");
    libro.pagine = 10;

    // Utilizzo 2° dichiarazione di struttura;

    strcpy(libro_2.autore, "Petrarca");
    strcpy(libro_2.titolo, "I promessi sposi");
    libro_2.pagine = 11;

    // Utilizzo 3° dichiarazione di struttura;

    strcpy(libro_3.autore, "Boccaccio");
    strcpy(libro_3.titolo, "Decamerone");
    libro_3.pagine = 12;

    struct s_libro libro_3_mezzo;

    strcpy(libro_3_mezzo.autore, "Ungaretti");
    strcpy(libro_3_mezzo.titolo, "Poesie Ermetiche");
    libro_3_mezzo.pagine = 13;

    // Utilizzo 4° dichiarazione di struttura;

    t_libro_4 libro_4;

    strcpy(libro_4.autore, "Pascoli");
    strcpy(libro_4.titolo, "10 Agosto");
    libro_4.pagine = 14;

    // Utilizzo 5° dichiarazione di struttura;

    t_libro_5 libro_5;

    strcpy(libro_5.autore, "Leopardi");
    strcpy(libro_5.titolo, "Il sabato del villaggio");
    libro_5.pagine = 15;

    // Creo un puntatore a struttura

    t_libro_5 *p;
    p = (t_libro_5 *)malloc(sizeof(t_libro_5));
    strcpy(p->autore, "D'Annunzio");
    strcpy(p->titolo, "La citta' morta");

    printf("Autore : %s \nTitolo : %s \n", p->autore, p->titolo);

    // Quando si tratta di puntatori a strutture si utilizza -> per accedere ai dati
    // Ma si può anche utilizzare il . come nelle normali strutture antecedendo (*puntatore)
    // (*p).autore == p->autore (L'operatore (.) ha le precedenza sul (*))

    printf("Autore_Puntatore : %s \nTitolo_Puntatore : %s \n", (*p).autore, (*p).titolo);

    // Nota: una struttura non può avere come membro una struttura dello stesso tipo!
    // Per assurdo: se fosse possibile, quale sarebbe lo spazio di allocazione?
}