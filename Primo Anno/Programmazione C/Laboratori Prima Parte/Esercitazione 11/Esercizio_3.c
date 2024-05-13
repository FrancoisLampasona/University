#include <stdio.h>
#include <string.h>

#define N 80

struct materie
{
    char materia[20];
    char nome_prof[20];
    char congome_prof[20];
    char periodo[20];
    int crediti;
    char superamento[20];
};

typedef struct materie insegnamenti;

void maxmateria(insegnamenti struttura[], int indice)
{
    int max = struttura[0].crediti;
    int conserva_indice = 0;
    for (int i = 1; i < indice; i++)
    {
        if (max < struttura[i].crediti)
        {
            max = struttura[i].crediti;
            conserva_indice = i;
        }
    }
    printf("La materia che assegna piu' crediti e' %s", struttura[conserva_indice].materia);
}

int main(int argc, const char *argv[])
{
    insegnamenti insegnamento[N];

    if (argc != 2)
    {
        printf("Errore nel passaggio dei parametri \n");
        return 0;
    }

    char nomefile[20];
    strcpy(nomefile, argv[1]);

    FILE *fp = fopen(nomefile, "r");

    if (fp == NULL)
    {
        printf("Errore apertura file\n");
        return 1;
    }

    int indice = 0;

    while (fscanf(fp, "%s %s %s %s %d %s", insegnamento[indice].materia, insegnamento[indice].nome_prof, insegnamento[indice].congome_prof, insegnamento[indice].periodo, &insegnamento[indice].crediti, insegnamento[indice].superamento) == 6)
    {
        indice++;
    }

    for (int i = 0; i < indice; i++)
    {
        printf("%s %s %s %s %d %s\n", insegnamento[i].materia, insegnamento[i].nome_prof, insegnamento[i].congome_prof, insegnamento[i].periodo, insegnamento[i].crediti, insegnamento[i].superamento);
    }

    printf("\n");
    maxmateria(insegnamento, indice);
}