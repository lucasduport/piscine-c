#include "my_calloc.h"

void *my_calloc(size_t n, size_t size)
{
    void *p = malloc(n * size);
    if (p == NULL)
        return NULL; 
    char *ptr = p;
    for (size_t i = 0; i < n * size; i++)
    {
        *(ptr + i) = 0;
    }
    return p;
}
