#include <stdio.h>

int main(void)
{
    int A = 2;
    int B = 5;
    int C, X = 3;

    // Approfondimento 1

    C = ((A && B) || (!B)) && (!A);

    // Approfondimento 2

    C = (A < X < B);
    // Non esiste in C si fa A<X && B<X
}
