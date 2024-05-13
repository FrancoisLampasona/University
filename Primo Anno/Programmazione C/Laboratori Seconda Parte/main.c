#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LUNG 20
#define MAX_RIGH 3

void Palindroma(char *s[]);

int main()
{
    char *String[MAX_RIGH];
    for (int i = 0; i < MAX_RIGH; i++)
    {
        String[i] = (char *)malloc(sizeof(char) * MAX_LUNG);
    }
    int val = 0;
    while (val < MAX_RIGH)
    {
        printf("inserisci le frasi: ");
        gets(String[val]);
        val++;
    }
    Palindroma(String);
    return 0;
}

void Palindroma(char *s[])
{
    for (int i = 0; i < MAX_RIGH; i++)
    {
        char *start = s[i];
        char *end = s[i] + strlen(s[i]) - 1;
        int isPalindrome = 1;
        while (start < end)
        {
            if (!isalpha(*start))
            {
                start++;
                continue;
            }
            if (!isalpha(*end))
            {
                end--;
                continue;
            }
            if (tolower(*start) != tolower(*end))
            {
                isPalindrome = 0;
                break;
            }
            start++;
            end--;
        }
        if (isPalindrome)
            printf("%s e' palindroma \n", s[i]);
        else
            printf("%s non e' palindroma \n", s[i]);
    }
}
