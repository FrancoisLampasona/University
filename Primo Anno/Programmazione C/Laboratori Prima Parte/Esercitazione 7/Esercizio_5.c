#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char a, b;

    printf("Inserisci il contenuto nella variabile : ");
    scanf("%c", &a);

    printf("Inserisci il contenuto nella variabile : ");
    scanf(" %c", &b);

    if (isalpha(a) && isalpha(b))
    {
        if (a != b && a > b)
        {
            printf("Prima : %c e poi : %c", b, a);
        }
        else if (a != b && b > a)
        {
            printf("Prima : %c e poi : %c", a, b);
        }
    }
    else if (isdigit(a) || isdigit(b))
    {
        printf("Almeno uno dei caratteri e' una cifra");
    }
}