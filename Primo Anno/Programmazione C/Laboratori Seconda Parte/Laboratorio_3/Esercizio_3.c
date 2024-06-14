#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindrome(const char *s, const size_t n)
{
    if (n <= 1)
    {
        return 1;
    }

    if (s[0] != s[n - 1])
    {
        return 0;
    }

    return palindrome(s + 1, n - 2);
}

int main(void)
{
    printf("%d", palindrome("ciaaic", strlen("ciaaic")));
}