#include <assert.h>
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
    for (size_t i = 0; i < n / 2 - 1; i++)
    {
        maxH(h->array, h->size, i);
    }
}

int pop(struct heap *heap)
{
    assert(heap->size > 0);
    heap->size--;
    if (heap->size < heap->capacity / 2 && heap->capacity > 8)
    {
        heap->capacity /= 2;
        heap = realloc(heap, sizeof(int) * heap->capacity);
    }
    int res = heap->array[0];
    heap->array[0] = heap->array[heap->size];
    make_it_h(heap);
    return res;
}
