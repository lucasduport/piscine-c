#include "palindrome.h"

#include <stddef.h>

static int isAlphaNum(char c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    if (c >= 'a' && c <= 'z')
        return 1;
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

int palindrome(const char *s)
{
    if (s == NULL)
        return 0;
    int len = 0;
    for (int i = 0; s[len] != 0; i++)
        len++;
    int i = 0;
    int j = len - 1;
    while (i < len && j >= 0)
    {
        if (isAlphaNum(s[i]) != 1)
        {
            i++;
            continue;
        }
        if (isAlphaNum(s[j]) != 1)
        {
            j--;
            continue;
        }
        if (s[i] != s[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}
