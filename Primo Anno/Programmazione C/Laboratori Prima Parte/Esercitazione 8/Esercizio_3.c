#include <stdio.h>
#include <string.h>
#define N 10

int main(void)
{
    char stringa_prima[N];
    char stringa_seconda[N];
    char intervallo[N];
    int h, h1, m, m1, orario, orario1;

    printf("Inserisci il primo orario:");
    scanf("%s", stringa_prima);

    printf("Inserisci il secondo orario :");
    scanf("%s", stringa_seconda);

    if (sscanf(stringa_prima, "%d:%d", &h, &m) != 2 && (h > 24 && h < 0 & m > 59 && m < 0))
    {
        printf("Errore nella prima battitura\n");
        return 0;
    }

    if (sscanf(stringa_seconda, "%d:%d", &h, &m) != 2 && (h > 24 && h < 0 & m > 59 && m < 0))
    {
        printf("Errore nella seconda battitura\n");
        return 0;
    }

    if (h < h1 && m < m1)
    {

        printf("L'orario della prima riga e' precedente alla seconda\n");

        orario = (h * 60) + m;
        orario1 = (h1 * 60) + m1;

        int diff;

        diff = (orario - orario1);
        itoa(diff, intervallo, 10);
    }
    else
    {
        return 0;
    }

    printf("Ci sono %s minuti di differenza", intervallo);
}