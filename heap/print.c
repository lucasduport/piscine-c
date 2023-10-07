#include <stdio.h>

#include "heap.h"

void print_heap(const struct heap *heap)
{
    size_t i = 0;
    while (i < heap->size)
    {
        size_t last = i;
        last++;
        printf("%d", heap->array[i]);
        if (2 * i + 1 >= heap->size)
        {
            i++;
        }
        i++;
    }
}
