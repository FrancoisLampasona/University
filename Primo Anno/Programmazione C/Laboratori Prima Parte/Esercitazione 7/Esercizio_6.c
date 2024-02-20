#include <stdio.h>
#include <ctype.h>

int main(void)
{

    char ch;
    int counter = 0;

    ch = getchar();

    while (ch != '\n')
    {
        if (isalpha(ch) && counter == 0)
        {
            ch=toupper(ch);
            counter++;
        }
        else if (isspace(ch))
        {
            counter = 0;
        }
        printf("%c",ch);
        ch = getchar();
    }
}