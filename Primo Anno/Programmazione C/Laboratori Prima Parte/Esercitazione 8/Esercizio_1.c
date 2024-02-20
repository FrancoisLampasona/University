#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 10

int main(void)
{
    char V[N];
    int alfabetici = 0;
    int numeri = 0;
    printf("Inserisci la stringa al suo interno: ");
    scanf("%s", V);

    int lunghezza = strlen(V);

    for (int i = 0; V[i] != '\0'; i++)
    {
        if (isalpha(V[i]))
        {
            alfabetici++;
        }
        else if (isdigit(V[i]))
        {
            numeri++;
        }
    }

    printf("lunghezza della stringa : %d\n", lunghezza);
    printf("alfabetici : %d\n", alfabetici);
    printf("numerici : %d\n", numeri);

    char *ret;
    ret = strstr(V, "come");
    if (ret == NULL)
    {
        printf("Non e' inclusa");
    }
    else
    {
        printf("Inclusa");
    }

}
