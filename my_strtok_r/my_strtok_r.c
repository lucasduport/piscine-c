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
        str = *saveptr;
    }
    size_t i = 0;
    for (; str[i] != 0; i++)
    {
        if (charInWord(str[i], delim) == 1)
        {
            *saveptr = str + i + 1;
            return str + i + 1;
        }
    }
    return str + i;
}

#include <stdio.h>

int main()
{
    char str[] = "Hey brother hey sister";
    char *rest = str;
    char *token = my_strtok_r(rest, " ", &rest);

    while (token[0] != 0)
    {
        printf("%s\n", token);
        token = my_strtok_r(NULL, " ", &rest);
    }

    return (0);
}
