#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define Righe 5
#define Colonne 5

// Stampa Matrice: nel prototipo va messa almeno la dimensione delle colonne della matrice, è comunque un passaggio per riferimento
void stampaMatrix(int Matrix[][Colonne])
{
    for (int i = 0; i < Righe; i++)
    {
        for (int j = 0; j < Colonne; j++)
        {
            printf("%d ", Matrix[i][j]);
        }
        printf("\n");
    }
}

// Stampa Matrice Dinamica: questa funzione stampa una matrice dinamica passata come doppio puntatore
void stampaMatrixDinamica(int **Matrix)
{
    for (int i = 0; i < Righe; i++)
    {
        for (int j = 0; j < Colonne; j++)
        {
            printf("%d ", Matrix[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    // Dichiarazione di una Matrice Quadrata Statica
    int Matrix_Quadrata[Righe][Colonne];

    srand(time(NULL));
    int number = 0;

    // Inserimento dei valori all'interno di una Matrice Quadrata Statica
    for (int i = 0; i < Righe; i++)
    {
        for (int j = 0; j < Colonne; j++)
        {
            Matrix_Quadrata[i][j] = ++number;
        }
    }

    // Stampare la matrice quadrata statica
    printf("Matrice Quadrata Statica:\n");
    stampaMatrix(Matrix_Quadrata);

    // Allocazione dinamica di una matrice quadrata
    int **Matrix_Quadra_Dinamica = (int **)malloc(sizeof(int *) * Righe);
    if (!Matrix_Quadra_Dinamica)
    {
        printf("Errore allocazione di memoria\n");
        exit(1);
    }

    // Allocazione delle colonne della matrice dinamica
    for (int i = 0; i < Righe; i++)
    {
        Matrix_Quadra_Dinamica[i] = (int *)malloc(Colonne * sizeof(int));
    }

    // Inserimento dei valori all'interno della matrice dinamica
    for (int i = 0; i < Righe; i++)
    {
        for (int j = 0; j < Colonne; j++)
        {
            Matrix_Quadra_Dinamica[i][j] = i * Colonne + j;
        }
    }

    printf("\nMatrice Quadrata Dinamica:\n");

    // Stampare la matrice quadrata dinamica
    stampaMatrixDinamica(Matrix_Quadra_Dinamica);

    // Deallocazione della memoria della matrice quadrata dinamica
    for (int i = 0; i < Righe; i++)
    {
        free(Matrix_Quadra_Dinamica[i]);
    }
    free(Matrix_Quadra_Dinamica);

    return 0;
}
