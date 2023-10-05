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

#include <stdio.h>
int main(void)
{
    const size_t size = 35;
    struct int_vector t = { .size = size,
                            .data = {
                                5,    8,    90,   3,    7,     64,   10224,
                                88,   39,   78,   20,   6,     9,    79,
                                30,   45,   908,  201,  73,    460,  1330,
                                37,   32,   13,   709,  310,   1998, 2000,
                                2020, 2021, 2022, 5600, 10000, 4560, 4800,
                            } };

    swap(t, 0, 1);
    printf("Before sorting:");
    for (size_t i = 0; i < size; i++)
        printf(" %d", t.data[i]);

    t = int_vector_bubble_sort(t);

    printf("\nAfter sorting:");
    for (size_t i = 0; i < size; i++)
        printf(" %d", t.data[i]);

    return 0;
}
