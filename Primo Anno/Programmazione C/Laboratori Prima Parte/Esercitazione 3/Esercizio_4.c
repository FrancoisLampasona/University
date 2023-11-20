#include <stdio.h>
#define BASE 100
#define BONUS 40
#define MALUS 20

int main(void)
{
    int price, features, months, years;

    printf("Inserisci il numero di features :");
    scanf("%d", &features);

    printf("Inserisci il numero di anni di possesso :");
    scanf("%d", &years);

    months = years * 12;

    price = BASE + BONUS * features - MALUS * months;

    printf("Il prezzo dello smartphone e' : %d\n", price);
}