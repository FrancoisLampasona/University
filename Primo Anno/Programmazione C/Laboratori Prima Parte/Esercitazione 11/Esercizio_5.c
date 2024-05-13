#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct GaraTxT
{
	char *nome_atleta;
	int punteggio;
} Atletica;

int confronta_atleti(const void *a, const void *b)
{
	Atletica *atleta1 = (Atletica *)a;
	Atletica *atleta2 = (Atletica *)b;
	return strcmp(atleta1->nome_atleta, atleta2->nome_atleta);
}

int main(int argc, const char *argv[])
{
	if (argc != 2)
	{
		printf("Errore nel passaggio dei parametri\n");
		return 1;
	}

	char *nome_file = (char *)malloc(strlen(argv[1]) + 1);
	strcpy(nome_file, argv[1]);

	FILE *fp = fopen(nome_file, "w+");
	if (fp == NULL)
	{
		printf("Errore nell'apertura del file\n");
		free(nome_file);
		return 1;
	}

	Atletica *atleti = calloc(100, sizeof(Atletica));
	char *Nomi[] = {"Andrea", "Mario", "Giovanni", "Francois", "Luca", "Milena", "Elisa", "Ettore", "Roberta", "Elia", "Francois"};
	srand(time(NULL));

	for (int i = 0; i < 100; i++)
	{
		int indice_nomi = rand() % 11;

		atleti[i].nome_atleta = malloc((strlen(Nomi[indice_nomi]) + 1) * sizeof(char));
		strcpy(atleti[i].nome_atleta, Nomi[indice_nomi]);
		atleti[i].punteggio = rand() % 50;

		fprintf(fp, "%s %d\n", atleti[i].nome_atleta, atleti[i].punteggio);
	}

	int max = 0;
	int indice_max = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 100; k++)
		{
			if (atleti[k].punteggio > max)
			{
				max = atleti[k].punteggio;
				indice_max = k;
			}
		}
		printf("Il classificato %d ha fatto %d\n", i+1, max);
		atleti[indice_max].punteggio = -1;
		max = 0;
	}

	qsort(atleti, 100, sizeof(Atletica), confronta_atleti);

	FILE *fp_2 = fopen("garaord.txt", "w+");
	if (fp_2 == NULL)
	{
		printf("Errore nell'apertura del file\n");
		free(nome_file);
		return 2;
	}

	for (int i = 0; i < 100; i++)
	{
		fprintf(fp_2, "%s %d\n", atleti[i].nome_atleta, atleti[i].punteggio);
	}

	for (int i = 0; i < 100; i++)
	{
		free(atleti[i].nome_atleta);
	}
	free(atleti);
	free(nome_file);
	fclose(fp);
	fclose(fp_2);

	return 0;
}
