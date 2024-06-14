#include <stdio.h>

int function(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return function(n - 1) + function(n - 2);
}

int main(void)
{
    printf("%d", function(10));
}