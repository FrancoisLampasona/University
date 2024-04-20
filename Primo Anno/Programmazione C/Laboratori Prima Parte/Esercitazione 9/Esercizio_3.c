#include <stdio.h>
#include <string.h>

#define N 80
#define M 20

int main() {
    FILE *f;
    char nomefile[N];
    char nomecity[M];
    char city_p[M], city_a[M];
    float orario_p, orario_a;
    int count_p = 0, count_a = 0;

    printf("Inserisci il nome del file: ");
    scanf("%s", nomefile);

    f = fopen(nomefile, "r");
    if (f == NULL) {
        printf("Il file non è stato aperto correttamente\n");
        return 1;
    }

    printf("Inserisci il nome della città: ");
    scanf("%s", nomecity);

    while (fscanf(f, "%s %f %s %f", city_p, &orario_p, city_a, &orario_a) == 4) {
        if (strcmp(nomecity, city_p) == 0) {
            count_p++;
        }
        if (strcmp(nomecity, city_a) == 0) {
            count_a++;
        }
    }

    printf("Dalla città %s ci sono:\n"
           "%d treni in partenza\n"
           "%d treni in arrivo\n",
           nomecity, count_p, count_a);

    fclose(f);
    return 0;
}
