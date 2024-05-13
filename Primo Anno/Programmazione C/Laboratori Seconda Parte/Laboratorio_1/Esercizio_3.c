#include <stdio.h>

void underscore(const char *s)
{
    if (*(s) != '\0')
    {
        printf("%c_", *(s));
        underscore(s + 1);
    }
    else
    {
        return;
    }
}

int main(void)
{
    underscore("ciao");
}