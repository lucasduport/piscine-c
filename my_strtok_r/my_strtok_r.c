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
        if (*saveptr != 0)
            str = *saveptr;
        else
            return 0;
    }
    if (str == NULL && *saveptr == NULL)
        return NULL;
    size_t i = 0;
    for (; str[i] != 0; i++)
    {
        if (charInWord(str[i], delim) == 1)
        {
            *saveptr = str + i + 1;
            str[i] = 0;
            return str;
        }
    }
    *saveptr = NULL;
    return str;
}
