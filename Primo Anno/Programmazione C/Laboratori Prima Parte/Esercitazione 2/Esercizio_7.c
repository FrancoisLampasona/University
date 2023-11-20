#include <stdio.h>

int main(void)
{

    float Tmp, V, m;

    printf("Inserisci il valore della tensione :");
    scanf("%f", &V);

    if (V <= 20)
    {
        m = (float)V / 15;
        Tmp = (float)V / m;
        printf("Il valore della temperatura e' %.2f", Tmp);
    }
    else if (V > 20 && V <= 55)
    {
        m = (float)(55 - 20) / (27 - 15);
        Tmp = (float)((V - 20) / m) + 15;
        printf("Il valore della temperatura e' %.2f", Tmp);
    }
    else if (V > 55 && V <= 100)
    {
        m = (float)(100 - 55) / (35 - 27);
        Tmp = (float)((V - 55) / m) + 27;
        printf("Il valore della temperatura e' %.2f", Tmp);
    }
}
