#include "my_memcpy.h"

void *my_memcpy(void *dest, const void *source, size_t num)
{
    char *cDst = dest;
    const char *cSrc = source;
    for (size_t i = 0; i < num && (cSrc + i) < cDst; i++)
    {
        cDst[i] = cSrc[i];
    }
    return dest;
}

int main(void)
{
    return 0;
}
