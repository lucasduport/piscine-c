#include "my_strtok_r.h"

static int charInWord(char c, const char *accept)
{
    for (size_t i = 0; accept[i] != 0; i++)
    {
        if (accept[i] == c)
            return 1;
    }
    return 0;
}

char *my_strtok_r(char *str, const char *delim, char **saveptr)
{
    size_t saveI = 0;
    if (str == NULL)
    {
        for (; saveptr[saveI + 1] != NULL; saveI++)
            continue;
    }
    str = saveptr[saveI];
    for (size_t i = 0; str[i] != 0; i++)
    {
        if (charInWord(str[i], delim) == 1)
        {
            saveptr[saveI + 1] = str + i;
            return str + i;
        }
    }
    return NULL;
}
