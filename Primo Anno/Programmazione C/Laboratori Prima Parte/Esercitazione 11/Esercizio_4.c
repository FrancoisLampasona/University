#include <stdio.h>

int main()
{

    unsigned char V[9] = {72, 242, 15, 250, 30, 34, 14, 2, 52};
    unsigned char *p = &V[1], *q = &V[5], c;
    while (q - p)
    {
        c = *p + *q;
        p++;
        q--;
        printf("%u ", c);
    }
}