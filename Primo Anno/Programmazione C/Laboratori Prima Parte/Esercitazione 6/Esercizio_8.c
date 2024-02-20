#include <stdio.h>
#include <limits.h>

#define True 1
#define False 0
#define Overflow 7

int testpitagorico(int a, int b, int c);

int main()
{
    for (int i = 1; i < 100; i++)
    {
        for (int k = 1; k < 100; k++)
        {
            for (int j = 1; j < 100; j++)
            {
                int risultato = testpitagorico(i, k, j);
                if (risultato == True)
                {
                    printf("%d^2 + %d^2 = %d^2\n", i, k, j);
                }
                else if (risultato == Overflow)
                {
                    i = 100;
                    k = 100;
                    j = 100;
                }
            }
        }
    }
}

int testpitagorico(int a, int b, int c)
{
    if (a * a + b * b < INT_MAX)
    {
        if (a * a + b * b == c * c)
        {
            return True;
        }
        else
        {
            return False;
        }
    }
    else
    {
        return Overflow;
    }
}