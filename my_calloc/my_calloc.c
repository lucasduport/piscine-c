#include "my_calloc.h"

void *my_calloc(size_t n, size_t size)
{
    char *p = malloc(n * size);
    if (p == NULL)
        return NULL;
    for (size_t i = 0; i < n; i++)
    {
        *(p + i) = 0;
    }
    void *voidP = p;
    return voidP;
}
