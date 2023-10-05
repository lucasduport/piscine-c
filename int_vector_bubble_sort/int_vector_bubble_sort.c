#include "int_vector_bubble_sort.h"

int isSorted(int arr[], size_t s)
{
    if (s == 0)
        return 1;
    for (size_t i = 0; i < s - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            return 0;
    }
    return 1;
}

static struct int_vector swap(struct int_vector vec, size_t i, size_t j)
{
    while (isSorted(vec.data, vec.size) == 0)
    {
        for (size_t i = 0; i < vec.size - 1; i++)
        {
            if (vec.data[i] > vec.data[i + 1])
            {
                int tmp = vec.data[i];
                vec.data[i] = vec.data[i + 1];
                vec.data[i + 1] = tmp;
            }
        }
    }
    return vec;
}
