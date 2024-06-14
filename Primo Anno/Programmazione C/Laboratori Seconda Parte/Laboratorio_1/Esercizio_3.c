#include <stdio.h>

void underscore(const char *s)
{
    if (*(s + 1) == '\0')
    {
        printf("_");
    }
    if (*(s) != '\0')
    {
        printf("_%c", *s);
        underscore(s + 1);
    }
}

int main(void)
{
    underscore("ciao");
}