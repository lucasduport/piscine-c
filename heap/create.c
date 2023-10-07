#include <stdlib.h>

#include "heap.h"

struct heap *create_heap(void)
{
    struct heap *h = malloc(sizeof(struct heap));
    if (h == NULL)
        return NULL;
    h->size = 0;
    h->capacity = 8;
    h->array = malloc(sizeof(int) * h->capacity);
    return h;
}
