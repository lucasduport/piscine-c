#include "my_strspn.h"

static int charInWord(char c, const char *accept)
{
    for (size_t i = 0; accept[i] != 0; c++)
    {
        if (accept[i] == c)
            return 1;
    }
    return 0;
}

size_t my_strspn(const char *s, const char *accept)
{
    size_t i = 0;
    for (; s[i] != 0 && charInWord(s[i], accept); i++)
        continue;
    return i;
}
