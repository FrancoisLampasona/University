#include <stdio.h>

int main(void)
{

    int a = 25;
    int b = 115;
    int c = 380;
    int d = 213;
    int min;
    int max;

    if (a < 0 || a > 1000)
    {
        a = 0;
        printf("Il valore a immesso non rientra nel range\n");
    }
    if (b < 0 || b > 1000)
    {
        b = 0;
        printf("Il valore b immesso non rientra nel range\n");
    }
    if (c < 0 || c > 1000)
    {
        c = 0;
        printf("Il valore c immesso non rientra nel range\n");
    }
    if (d < 0 || d > 1000)
    {
        d = 0;
        printf("Il valore d immesso non rientra nel range\n");
    }

    if (a < b)
    {
        min = a;
        max = b;
    }
    else
    {
        max = a;
        min = b;
    }

    if (max < c)
    {
        max = c;
        if (min > c)
            min = c;
    }

    if (max < d)
    {
        max = d;
        if (min > d)
            min = d;
    }

    printf("Il valore minimo e' %d\nIl valore massimo e' %d\nLa differenza tra i due valori e' %d\n", min, max, max - min);
}