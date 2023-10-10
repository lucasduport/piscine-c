#include "my_memcmp.h"

#include <stddef.h>

int my_memcmp(const void *s1, const void *s2, size_t num)
{
    const unsigned char *c1 = s1;
    const unsigned char *c2 = s2;
    for (size_t i = 0; i < num; i++)
    {
        if (c1[i] != c2[i])
            return c1[i] - c2[i];
    }
    return 0;
}
