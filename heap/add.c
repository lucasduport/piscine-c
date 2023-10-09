#include <stdlib.h>

#include "heap.h"

static void maxH(int arr[], size_t s, size_t i)
{
    size_t maxI = i;
    size_t l = 2 * i + 1;
    size_t r = 2 * i + 2;
    if (l < s && arr[l] > arr[maxI])
        maxI = l;
    if (r < s && arr[r] > arr[maxI])
        maxI = r;
    if (maxI != i)
    {
        int tmp = arr[i];
        arr[i] = arr[maxI];
        arr[maxI] = tmp;
        maxH(arr, s, maxI);
    }
}

static void make_it_h(struct heap *h)
{
    if (h->size == 0 || h->size == 1)
        return;
    for (int i = h->size / 2 - 1; i >= 0; i--)
        maxH(h->array, h->size, i);
}

void add(struct heap *heap, int val)
{
    if ((heap->size + 1) > heap->capacity)
    {
        heap->capacity *= 2;
        heap->array = realloc(heap->array, heap->capacity * sizeof(int));
        if (heap == NULL)
            return;
    }
    heap->array[heap->size] = val;
    heap->size++;
    make_it_h(heap);
}
