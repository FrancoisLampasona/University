#include <stdio.h>

int main(void)
{
    int gg, mese, anno;

    printf("Inserisci la data nella forma gg/mese/anno : ");
    scanf("%d/%d/%d", &gg, &mese, &anno);

    if (gg <= 31)
    {

        switch (mese)
        {
        case 1:
            printf("La data e' %d/Gennaio/%d", gg, anno);
            break;
        case 2:
            printf("La data e' %d/Febbraio/%d", gg, anno);
            break;
        case 3:
            printf("La data e' %d/Marzo/%d", gg, anno);
            break;
        case 4:
            printf("La data e' %d/Aprile/%d", gg, anno);
            break;
        case 5:
            printf("La data e' %d/Maggio/%d", gg, anno);
            break;
        case 6:
            printf("La data e' %d/Giugno/%d", gg, anno);
            break;
        case 7:
            printf("La data e' %d/Luglio/%d", gg, anno);
            break;
        case 8:
            printf("La data e' %d/Agosto/%d", gg, anno);
            break;
        case 9:
            printf("La data e' %d/Settembre/%d", gg, anno);
            break;
        case 10:
            printf("La data e' %d/Ottobre/%d", gg, anno);
            break;
        case 11:
            printf("La data e' %d/Novembre/%d", gg, anno);
            break;
        case 12:
            printf("La data e' %d/Dicembre/%d", gg, anno);
            break;

        default:
            printf("Il mese inserito non e' valido\n");
            break;
        }
    }
    else
    {
        printf("Il giorno inserito non e' valido\n");
    }
}