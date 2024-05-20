#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct esercizio {
    char *cognome_nome;
    int num;
    char *matricola;
    int voto;
} gestore;

void inserisci(gestore *studenti, char *cognome_nome, int num, char *matricola, int voto, int *indice) {
    studenti[*indice].cognome_nome = (char *)malloc((strlen(cognome_nome) + 1) * sizeof(char));
    studenti[*indice].matricola = (char *)malloc((strlen(matricola) + 1) * sizeof(char));

    if (studenti[*indice].cognome_nome == NULL || studenti[*indice].matricola == NULL) {
        printf("Errore allocazione di memoria\n");
        return;
    }

    strcpy(studenti[*indice].cognome_nome, cognome_nome);
    strcpy(studenti[*indice].matricola, matricola);
    studenti[*indice].num = num;
    studenti[*indice].voto = voto;
    (*indice)++;
}

void cancella_tramite_nome(gestore *studenti, int *indice, char *cognome_nome) {
    for (int i = 0; i < *indice; i++) {
        if (strcmp(studenti[i].cognome_nome, cognome_nome) == 0) {
            free(studenti[i].cognome_nome);
            free(studenti[i].matricola);
            for (int j = i; j < *indice - 1; j++) {
                studenti[j] = studenti[j + 1];
            }
            (*indice)--;
            return;
        }
    }
    printf("Studente non trovato.\n");
}

void cancella_tramite_matricola(gestore *studenti, int *indice, char *matricola) {
    for (int i = 0; i < *indice; i++) {
        if (strcmp(studenti[i].matricola, matricola) == 0) {
            free(studenti[i].cognome_nome);
            free(studenti[i].matricola);
            for (int j = i; j < *indice - 1; j++) {
                studenti[j] = studenti[j + 1];
            }
            (*indice)--;
            return;
        }
    }
    printf("Studente non trovato.\n");
}

void visualizza_tramite_nome(gestore *studenti, int indice, char *cognome_nome) {
    for (int i = 0; i < indice; i++) {
        if (strcmp(studenti[i].cognome_nome, cognome_nome) == 0) {
            printf("Studente: %s, Matricola: %s, Voto: %d\n", studenti[i].cognome_nome, studenti[i].matricola, studenti[i].voto);
            return;
        }
    }
    printf("Studente non trovato.\n");
}

void visualizza_tramite_matricola(gestore *studenti, int indice, char *matricola) {
    for (int i = 0; i < indice; i++) {
        if (strcmp(studenti[i].matricola, matricola) == 0) {
            printf("Studente: %s, Matricola: %s, Voto: %d\n", studenti[i].cognome_nome, studenti[i].matricola, studenti[i].voto);
            return;
        }
    }
    printf("Studente non trovato.\n");
}

void stampa_all(gestore *studenti, int indice) {
    for (int i = 0; i < indice; i++) {
        printf("Studente: %s, Matricola: %s, Voto: %d\n", studenti[i].cognome_nome, studenti[i].matricola, studenti[i].voto);
    }
}

void leggi_dati(gestore *studenti, int *indice, char *nomefile) {
    FILE *fp = fopen(nomefile, "r");
    if (!fp) {
        printf("Errore nell'apertura del file.\n");
        return;
    }

    char cognome_nome[50];
    char matricola[20];
    int num, voto;

    while (fscanf(fp, "%s %d %s %d", cognome_nome, &num, matricola, &voto) != EOF) {
        inserisci(studenti, cognome_nome, num, matricola, voto, indice);
    }

    fclose(fp);
}

void salva_dati(gestore *studenti, int indice, char *nomefile) {
    FILE *fp = fopen(nomefile, "w");
    if (!fp) {
        printf("Errore nell'apertura del file.\n");
        return;
    }

    for (int i = 0; i < indice; i++) {
        fprintf(fp, "%s %d %s %d\n", studenti[i].cognome_nome, studenti[i].num, studenti[i].matricola, studenti[i].voto);
    }

    fclose(fp);
}

int main(int argc, const char *argv[]) {
   
    if (argc != 2) {
        printf("Errore passaggio parametri\n");
        return 0;
    }

    gestore *studenti;
    studenti = (gestore *)malloc(10 * sizeof(gestore));

    if (studenti == NULL) {
        printf("Errore allocazione di memoria\n");
        return 1;
    }

    char comando;
    char cognome_nome[50];
    char matricola[20];
    int num, voto;
    int indice = 0;

    while (1) {
        printf("Inserisci comando: ");
        scanf(" %c", &comando);

        switch (comando) {
            case 'I':
                scanf("%s %d %s %d", cognome_nome, &num, matricola, &voto);
                inserisci(studenti, cognome_nome, num, matricola, voto, &indice);
                break;
            case 'C':
                scanf("%s", cognome_nome);
                if (strcmp(cognome_nome, "") != 0) {
                    cancella_tramite_nome(studenti, &indice, cognome_nome);
                } else {
                    scanf("%s", matricola);
                    cancella_tramite_matricola(studenti, &indice, matricola);
                }
                break;
            case 'V':
                scanf("%s", cognome_nome);
                if (strcmp(cognome_nome, "") != 0) {
                    visualizza_tramite_nome(studenti, indice, cognome_nome);
                } else {
                    scanf("%s", matricola);
                    visualizza_tramite_matricola(studenti, indice, matricola);
                }
                break;
            case 'P':
                stampa_all(studenti, indice);
                break;
            case 'L':
                scanf("%s", cognome_nome);
                leggi_dati(studenti, &indice, cognome_nome);
                break;
            case 'S':
                scanf("%s", cognome_nome);
                salva_dati(studenti, indice, cognome_nome);
                break;
            default:
                printf("Comando non riconosciuto.\n");
                break;
        }
    }

    for (int i = 0; i < indice; i++) {
        free(studenti[i].cognome_nome);
        free(studenti[i].matricola);
    }
    free(studenti);

    return 0;
}
