#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char maxCommonChar(char *s, char *t)
{
    char caratteri_s[256] = {0};
    char caratteri_t[256] = {0};

    for (int i = 0; i < strlen(s); i++)
    {
        caratteri_s[s[i]]++;
    }

    for (int k = 0; k < strlen(t); k++)
    {
        caratteri_t[t[k]]++;
    }

    int max = 0;
    char ritorno = '\0';

    for (int i = 0; i < 256; i++)
    {
        int somma = caratteri_s[i] + caratteri_t[i];
        if (caratteri_s[i] > 0 && caratteri_t[i] > 0 && max < somma)
        {

            max = somma;
            ritorno = (char)i;
        }
    }

    return ritorno;
}

int main(void)
{
    char *s = (char *)malloc(sizeof(char) * 30);
    char *t = (char *)malloc(sizeof(char) * 30);

    printf("Inserisci la prima stringa : ");
    scanf("%s", s);

    printf("Inserisci la seconda stringa : ");
    scanf("%s", t);

    char finale = maxCommonChar(s, t);
    if (!finale)
    {
        printf("Non hanno caratteri comuni");
    }
    else
    {
        printf("Il carattere e' %c", finale);
    }

    free(s);
    free(t);
}