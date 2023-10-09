#include "heap_sort.h"

static void maxH(int *arr, size_t s, size_t i)
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

void heapify(int *array, size_t size)
{
    if (size == 0 || size == 1)
        return;
    for (int i = size / 2 - 1; i >= 0; i--)
        maxH(array, size, i);
}

void heap_sort(int *array, size_t size)
{
    for (int i = size; i >= 1; i--)
    {
        heapify(array, i);
        int tmp = array[0];
        array[0] = array[i - 1];
        array[i - 1] = tmp;
    }
}
