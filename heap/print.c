#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

static void DFS(const struct heap *h, size_t i)
{
    if (i >= h->size)
        return;
    printf("%d", h->array[i]);
    if (2 * i + 1 < h->size)
    {
        printf(" ");
        DFS(h, 2 * i + 1);
    }
    if (2 * i + 1 < h->size)
    {
        printf(" ");
        DFS(h, 2 * i + 2);
    }
}

void print_heap(const struct heap *heap)
{
    if (heap->size == 0)
        return;
    DFS(heap, 0);
    printf("\n");
}
