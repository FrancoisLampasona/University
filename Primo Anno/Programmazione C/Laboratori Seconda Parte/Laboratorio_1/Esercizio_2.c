#include <stdio.h>
#include <stdlib.h>

int recEuclide(int a, int b)
{
    int q;

    if (b == 0)
    {
        return a;
    }

    if (a % b == 0)
    {
        return b;
    }
    recEuclide(b, a % b);
}

int main(void)
{

    printf("L'MCD e' %d", recEuclide(10, 20));
}