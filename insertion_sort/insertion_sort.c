#include "insertion_sort.h"

#include <stddef.h>

static void swap(void **arr, size_t i, size_t j)
{
    void *tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void insertion_sort(void **array, f_cmp comp)
{
    if (array == NULL)
        return;
    size_t i = 1;
    while (array[i] != NULL)
    {
        size_t j = i;
        while (j > 0 && (*comp)(array[j - 1], array[j]) > 0)
        {
            swap(array, j, j - 1);
            j--;
        }
        i++;
    }
}
