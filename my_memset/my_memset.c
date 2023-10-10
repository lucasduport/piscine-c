#include "my_memset.h"

void *my_memset(void *s, int c, size_t n)
{
    if (s == NULL)
        return NULL;
    char *cast = s;
    for (size_t i = 0; i < n; i++)
    {
        cast[i] = c;
    }
    return s;
}
