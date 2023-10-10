#include "my_memmove.h"

void *my_memmove(void *dest, const void *src, size_t n)
{
    char *cDest = dest;
    const char *cSrc = src;
    for (size_t i = 0; i < n; i++)
    {
        if (cSrc <= cDest + i && cDest + i < cSrc + n)
            continue;
        cDest[i] = cSrc[i];
    }
    return dest;
}
