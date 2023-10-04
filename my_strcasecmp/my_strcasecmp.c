#include "my_strcasecmp.h"

#include <stddef.h>

static char toMaj(char c)
{
    if (c >= 'a' && c <= 'z')
        return c + ('A' - 'a');
    return c;
}

int my_strcmp(const char *s1, const char *s2)
{
    size_t i = 0;
    for (; toMaj(s1[i]) == toMaj(s2[i]) && s1[i] != 0 && s2[i] != 0; i++)
        continue;
    if (toMaj(s1[i]) == toMaj(s2[i]) && s1[i] == 0)
        return 0;
    return toMaj(s1[i]) - toMaj(s2[i]);
}
