#include <stdio.h>
#include <math.h>

int main(void)
{

    int a, b, c;

    printf("Inserisci a , b e c :");
    scanf("%d %d %d", &a, &b, &c);

    float delta = (b * b) - (4 * a * c);
    float x1 = (-b + sqrt(delta)) / (2 * a), x2 = (- b - sqrt(delta)) / (2 * a);

    if (delta > 0)
    {
        printf("Ci sono due soluzioni separate : %.2f %.2f", x1, x2);
    }
    else if (delta == 0)
    {
        x1 = (-b) / 2;
        x2 = x1;

        printf("Le due soluzioni sono uguali e sono : %.2f e %.2f", x1, x2);
    }
    else if (delta < 0)
    {
        printf("Non ci sono soluzioni reali");
    }
}