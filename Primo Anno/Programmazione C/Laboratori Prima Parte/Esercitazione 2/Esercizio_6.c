#include <stdio.h>

int main(void)
{

    int a;

    printf("Inserisci il valore del tuo numero :");
    scanf("%d", &a);

    if (a < 0)
    {
        a = -a;
        printf("Il valore assoluto del numero e' %d", a);
    }
    else
    {
        printf("Il valore assoluto del numero e' %d", a);
    }
    
}