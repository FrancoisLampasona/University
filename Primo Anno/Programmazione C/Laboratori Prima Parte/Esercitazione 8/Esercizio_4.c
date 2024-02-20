#include <stdio.h>
#include <string.h>

int main()
{
    char stringa[61];
    int lunghezza_parole[5] = {0};
    int lunghezza_totale = 0;
    int num_parole = 0;

    printf("Inserisci una stringa di massimo 5 parole (massimo 60 caratteri): ");
    fgets(stringa, 61, stdin);

    if (stringa[strlen(stringa) - 1] == '\n')
    {
        stringa[strlen(stringa) - 1] = '\0';
    }

    char *token = strtok(stringa, " ");
    while (token != NULL && num_parole < 5)
    {
        int lunghezza_parola = strlen(token);
        lunghezza_parole[num_parole] = lunghezza_parola;
        lunghezza_totale += lunghezza_parola;
        num_parole++;
        token = strtok(NULL, " ");
    }

    float media = (float)lunghezza_totale / num_parole;
    int counter = 0;

    printf("La stringa contiene %d parole\n", num_parole);
    printf("La lunghezza media delle parole e %.2f caratteri\n", media);
    printf("La stringa contiene:\n");

    for (int i = 0; i < num_parole; i++)
    {
        int counter = 1;               
        if (lunghezza_parole[i] != -1) 
        {
            for (int k = i + 1; k < num_parole; k++)
            {
                if (lunghezza_parole[i] == lunghezza_parole[k])
                {
                    counter++;
                    lunghezza_parole[k] = -1; 
                }
            }
            printf("- %d parola da %d caratteri\n", counter, lunghezza_parole[i]);
        }
    }

    return 0;
}