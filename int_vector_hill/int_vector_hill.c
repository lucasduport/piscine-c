#include "int_vector_hill.h"

int int_vector_hill(struct int_vector vec)
{
    if (vec.size == 0)
    {
        return -1;
    }
    size_t i = 0;
    for (; i < vec.size - 1 && vec.data[i] <= vec.data[i + 1]; i++)
        continue;
    for (; i > 0 && vec.data[i] == vec.data[i - 1]; i--)
        continue;
    int top = i;
    for (; i < vec.size - 1 && vec.data[i] == vec.data[i + 1]; i++)
        continue;
    for (; i < vec.size - 1 && vec.data[i] >= vec.data[i + 1]; i++)
        continue;
    if (vec.data[0] < 0 || vec.data[vec.size - 1] < 0 || i != vec.size - 1)
        return -1;
    return top;
}
