#include "int_vector_insert_sort.h"

static struct int_vector swap(struct int_vector vec, size_t i, size_t j)
{
    int tmp = vec.data[i];
    vec.data[i] = vec.data[j];
    vec.data[j] = tmp;
    return vec;
}

struct int_vector int_vector_insert_sort(struct int_vector vec)
{
    size_t i = 0;
    while (i < INT_VECTOR_LENGTH)
    {
        size_t j = i;
        while (j > 0 && vec.data[j - 1] > vec.data[j])
        {
            swap(vec, j, j - 1);
            j--;
        }
        i++;
    }
    return vec;
}
