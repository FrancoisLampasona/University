#include <stdio.h>

int main(void)
{

    int A, B, C;

    // Assumo A e B cateti

    A = 3;
    B = 4;
    C = 5;

    if (A < (B + C) && B < (A + C) && C < (A + B))
    {

        printf("Il triangolo e' Valido\n");

        if (A == (B + C) || B == (A + C) || C == (A + B))
        {
            printf("Il triangolo e' Degenere\n");
        }

        if (A * A + B * B == C * C)
        {
            printf("Il triangolo e' Rettangolo\n");
        }

        if (A == B && B == C && A == C)
        {
            printf("Il triangolo e' Equilatero\n");
        }

        if (A == B && B == C && A != C)
        {
            printf("Il triangolo e' Isoscele\n");
        }

        if (A != B && B != A & C != A)
        {
            printf("Il triangolo e' Scaleno\n");
        }
    }
}