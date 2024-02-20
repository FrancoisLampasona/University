#include <stdio.h>
#include <ctype.h>
#define N 25

int main(void)
{

    char V[N];
    int parola = 0;

    printf("Inserisci una stringa:");
    fgets(V, N, stdin);

    if (isalpha(V[0]))
        parola++;

    for (int i = 0; V[i] != '\0'; i++)
    {

        if (isalpha(V[i]) && islower(V[i]))
        {
            V[i] = toupper(V[i]);
        }
        else if (isspace(V[i]))
        {
            V[i] = '_';
            if (isalpha(V[i + 1]))
            {
                parola++;
            }
        }
        else if (isdigit(V[i]))
        {
            V[i] = '*';
        }
    }

    printf("%s\n", V);
    printf("%d", parola);
}