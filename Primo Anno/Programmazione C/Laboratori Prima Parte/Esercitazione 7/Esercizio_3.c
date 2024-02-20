#include <stdio.h>
#include <ctype.h>

int main(void)
{

    char ch;
    int caratteri_introdotti = 0, caratteri_alfabetici = 0, caratteri_maiuscoli = 0, cife_decimali = 0, spaziatura = 0;
    int parola = 0, counter = 0;

    ch = getchar();

    while (ch != '\n')
    {

        caratteri_introdotti++;
        if (isalpha(ch))
        {
            if (counter > 2)
            {
                parola++;
                counter = 0;
            }

            caratteri_alfabetici++;
            counter++;
        }
        else if (isupper(ch))
        {
            caratteri_maiuscoli++;
            counter = 0;
        }
        else if (isdigit(ch))
        {
            cife_decimali++;
            counter = 0;
        }
        else if (isspace(ch))
        {
            spaziatura++;
            counter = 0;
        }

        ch = getchar();
    }

    printf("Caratteri Introdotti: %d\nCaratteri Alfabetici: %d\nCaratteri Maiuscoli: %d\nCifre Decimali : %d\nSpaziatura : %d\nParole : %d\n", caratteri_introdotti, caratteri_alfabetici, caratteri_maiuscoli, cife_decimali, spaziatura, parola);
}