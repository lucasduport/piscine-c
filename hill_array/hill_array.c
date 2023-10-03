#include "hill_array.h"

int top_of_the_hill(int tab[], size_t len)
{
    if (len == 0)
        return 0;
    size_t i = 0;
    for (; i < len - 1 && tab[i] <= tab[i + 1]; i++)
        continue;
    for (; i > 0 && tab[i] == tab[i - 1]; i--)
        continue;
    int top = i;
    for (; i < len - 1 && tab[i] == tab[i + 1]; i++)
        continue;
    for (; i < len - 1 && tab[i] >= tab[i + 1]; i++)
        continue;
    if (i == len - 1)
        return top;
    return -1;
}
