#include <stdio.h>
#include <math.h>

float invsin(float z1, float z2, float k, float e);

int main()
{
    float a, b, c, e;

    printf("Inserisci gli estremi dell'intervallo :");
    scanf("%f", &a);

    printf("Inserisci gli estremi dell'intervallo :");
    scanf("%f", &b);

    printf("Inserisci il passo:");
    scanf("%f", &c);

    printf("Inserisci la precisione:");
    scanf("%f", &e);

    printf("%.2f", invsin(a, b, c, e));
    return 0;
}

float invsin(float z1, float z2, float k, float e)
{

    float z;

    do
    {

        z = (z1 + z2) / 2;

        if (sin(z) > k)

            z2 = z;

        else

            z1 = z;

    } while (sin(z) != k && ((z2 - z1) / 2.0) > e);

    return z;
}
