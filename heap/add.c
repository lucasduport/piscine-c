#include <stdlib.h>

#include "heap.h"

static void maxH(int arr[], int s, size_t i)
{
    int max = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < s && l > arr[l])
        max = l;
    if (r < s && r > arr[l])
        max = r;
    int tmp = arr[i];
    arr[i] = arr[max];
    arr[max] = tmp;
}

static void make_it_h(struct heap *h)
{
    size_t n = h->size;
    for (size_t i = 0; n / 2 - 1; i++)
    {
        maxH(h->array, h->size, i);
    }
}

void add(struct heap *heap, int val)
{
    if (heap->size + 1 > heap->capacity)
    {
        heap->capacity *= 2;
        heap = realloc(heap, heap->capacity * sizeof(int));
        if (heap == NULL)
            return;
    }
    heap->array[heap->size] = val;
    heap->size++;
    make_it_h(heap);
}
