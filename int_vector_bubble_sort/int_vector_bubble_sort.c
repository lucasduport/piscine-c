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
    struct int_vector *v = &vec;
    int tmp = v->data[i];
    v->data[i] = v->data[j];
    v->data[j] = tmp;
    return vec;
}

struct int_vector int_vector_bubble_sort(struct int_vector vec)
{
    while (isSorted(vec.data, vec.size) == 0)
    {
        for (size_t i = 0; i < vec.size - 1; i++)
        {
            if (vec.data[i] > vec.data[i + 1])
            {
                vec = swap(vec, i, i + 1);
            }
        }
    }
    return vec;
}
