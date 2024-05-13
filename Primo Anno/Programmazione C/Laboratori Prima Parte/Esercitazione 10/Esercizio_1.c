#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    if (argc != 3)
    {
        printf("Errore nel passaggio dei parametri !");
        return 1;
    }

    int arg1 = atoi(argv[1]);
    int arg2 = atoi(argv[2]);

    if ((arg1 >= -10000 && arg1 <= 10000) && (arg2 >= -10000 && arg2 <= 10000))
    {
        int sum = arg1 + arg2;
        printf("La somma e' %d\n", sum);
    }
    else
    {
        printf("I parametri devono essere compresi tra -10000 e 10000.\n");
        return 1;
    }

    return 0;
}
