// Si scriva la funzione char *ControllaFile(char *namefile,char *buff) in cui dato *namefile file
// di testo contenente in ogni riga una parola, lo copi nella variabile char *buff ed infine restituisca una
// stringa contenente la parola pi`u lunga nel testo.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ControllaFile(char *namefile, char *buff)
{
    if (!namefile)
    {
        printf("Errore passaggio nome file\n");
        exit(1);
    }

    FILE *fp = fopen(namefile, "r");
    if (!fp)
    {
        printf("Errore apertura file\n");
        exit(2);
    }

    buff[0] = '\0';

    char *longest_word = NULL;
    char current_word[256];
    size_t max_len = 0;

    while (fscanf(fp, "%s", current_word) != EOF)
    {
        strcat(buff, current_word);
        strcat(buff, "\n");

        size_t len = strlen(current_word);
        if (len > max_len)
        {
            max_len = len;
            longest_word = strdup(current_word);
        }
    }

    fclose(fp);

    return longest_word;
}

int main(void)
{
    char *namefile = strdup("testo_file_1.txt");
    char *buff;
    char *stringa = ControllaFile(namefile, buff);
    puts(stringa);
}