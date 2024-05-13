#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    if (argc != 4)
    {
        printf("Errore nel passaggio dei parametri !");
        return 1;
    }

    int val_1 = atoi(argv[1]);
    int val_2 = atoi(argv[2]);
    char ch = argv[3][0];

    switch (ch)
    {
    case 'a':
        printf("La somma e' %d", val_1 + val_2);
        break;
    case 'b':
        printf("La differenza e' %d", val_1 - val_2);
        break;
    case 'c':
        printf("Il prodotto e' %d", val_1 * val_2);
        break;
    case 'd':
        if (val_2 != 0)
            printf("Il quoziente e' %d", val_1 / val_2);
        else
            printf("Errore: divisione per zero");
        break;
    default:
        printf("Operazione non riconosciuta");
        break;
    }

    return 0;
}
