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
    if (str == NULL)
    {
        if (*saveptr == NULL)
            return NULL;
        str = *saveptr;
    }
    size_t i = 0;
    for (; str[i] != 0 && (charInWord(str[i], delim) == 1); i++)
        continue;
    str = str + i;
    i = 0;
    for (; str[i] != 0; i++)
    {
        if (charInWord(str[i], delim) == 1)
        {
            size_t j = i;
            for (; str[j] != 0 && charInWord(str[j], delim) == 1; j++)
                continue;
            *saveptr = str + j;
            str[i] = 0;
            return str;
        }
    }
    if (str[i] == 0)
    {
        if (i == 0)
            return NULL;
        *saveptr = NULL;
    }
    return str;
}
