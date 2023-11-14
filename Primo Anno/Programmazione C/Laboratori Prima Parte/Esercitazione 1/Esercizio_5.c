#include <stdio.h>

int main(void)
{

    int operand1, operand2, result;

    printf("Inserisci il valore del primo numero: ");
    scanf("%d", &operand1);

    printf("Inserisci il valore del secondo numero: ");
    scanf("%d", &operand2);

    result = operand1 + operand2;

    printf("La somma e' %d", result);


}