#include "my_memmove.h"

void *my_memmove(void *dest, const void *src, size_t n)
{
    if (src == dest || n == 0)
        return dest;
    char *cDest = dest;
    const char *cSrc = src;
    if (cSrc <= cDest && cDest < cSrc + n)
    {
        for (int i = n - 1; i >= 0; i--)
            cDest[i] = cSrc[i];
    }
    else
    {
        for (size_t i = 0; i < n; i++)
            cDest[i] = cSrc[i];
    }
    return dest;
}
