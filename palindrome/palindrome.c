#include "palindrome.h"

#include <stddef.h>

int palindrome(const char *s)
{
    if (s == NULL)
        return 0;
    size_t len = 0;
    for (; s[len] != 0; len++)
        continue;
    for (size_t i = 0; i < len / 2; i++)
    {
        if (s[i] != s[len - 1 - i])
            return 0;
    }
    return 1;
}
