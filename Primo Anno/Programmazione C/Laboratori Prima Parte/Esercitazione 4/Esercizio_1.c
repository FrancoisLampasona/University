#include <stdio.h>

int main(void)
{
    float a, b, c;
    printf("Inserisci i valori di a b e c:");
    scanf("%f%f%f",&a,&b,&c);

    float determinante = (b * b) - (4 * a * c);

    if (determinante < 0)
    {
        printf("Non esistono soluzioni reali\n");
    }
    else if(determinante > 0)
    {
        printf("Esistono due soluzioni distinte");
    }
    else if(determinante == 0)
    {
        printf("Esistono due soluzioni coincidenti");
    }
}