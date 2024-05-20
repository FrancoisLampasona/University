#include <stdio.h>

union myUnion
{
    int n;
    char s[5];
};

int main(void)
{
    union myUnion u;
    u.n = 1862270976 + 6356992 + 26880 + 67;
    u.s[4] = '\0';
    printf("int: %d\nstr: %s\n", u.n, u.s);
}

//    Una unione (o union) permette di condividere la stessa zona di memoria per variabili di tipo diverso
//    Il metodo di definizione ed accesso è analogo a quello delle struct, ma lo spazio di allocazione è condiviso tra i membri
//    Lo spazio di allocazione di una union è uguale allo spazio di allocazione del tipo più grande che contiene 
