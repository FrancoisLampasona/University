#include <stdio.h>

int main(void)
{

    int a;
    int b;
    int x;

    printf("Inserisci la variabile a :\n");
    scanf("%d", &a);

    printf("Inserisci la variabile b :\n");
    scanf("%d", &b);

    x = -b / a;

    printf("Il risultato è %d", x);
    
}