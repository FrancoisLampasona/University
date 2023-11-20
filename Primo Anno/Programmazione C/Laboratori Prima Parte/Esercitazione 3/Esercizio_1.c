#include <stdio.h>

int main(void)
{
    int intero1, intero2;
    float reale1, reale2;

    printf("Inserisci i valori dei numeri (Rispettando l'ordine) :");
    scanf("%d%d%f%f", &intero1, &intero2, &reale1, &reale2);

    printf("Variabili\tValori\nintero1 intero2 %5.d %5.d\nreale1 %5.2f\nreale2 %5.2f\n", intero1, intero2, reale1, reale2);
}