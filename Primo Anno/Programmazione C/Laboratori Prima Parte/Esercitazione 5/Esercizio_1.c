#include <stdio.h>

int main(void)
{

    int a = 34;
    int b = 18;
    int resto;
    int count = 0;

    while (b != 0)
    {
        count++;
        resto = a % b;
        a = b;
        b = resto;
        printf("Passo %d : %d %% %d\n", count, a, b);
    }

    printf("L'MCD e' : %d\n", a);
}