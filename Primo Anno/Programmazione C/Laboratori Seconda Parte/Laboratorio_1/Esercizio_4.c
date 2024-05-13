#include <stdio.h>
#include <string.h>

void reverse(const char *s)
{
    if (*s != '\0') {
        reverse(s + 1);
        printf("%c", *s);
    }
}

int main(void)
{

    reverse("ciao");
}