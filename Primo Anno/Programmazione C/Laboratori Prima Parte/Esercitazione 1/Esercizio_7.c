#include <stdio.h>

int main(void)
{

    char Lettera;
    int Celsius, Fahrenheit;

    printf("Inserisci una lettera : ");
    scanf("%c", &Lettera);

    switch (Lettera)
    {
    case 'C':
        printf("Inserisci i gradi : ");
        scanf("%d", &Celsius);
        Fahrenheit = (Celsius * 9 / 5) + 32;
        break;

    case 'F':
        printf("Inserisci i gradi : ");
        scanf("%d", &Fahrenheit);
        Celsius = (Fahrenheit - 32) * 5 / 9;
        break;
    }

    printf("I gradi in Celsius sono : %d C \n", Celsius);
    printf("I gradi in Fahrenheit sono : %d F \n", Fahrenheit);
}