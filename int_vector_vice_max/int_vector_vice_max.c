#include "int_vector_vice_max.h"

int int_vector_vice_max(const struct int_vector vec)
{
    int max2 = vec.data[0];
    int max = vec.data[0];
    for(size_t i = 0; i < vec.size; i++)
    {
        if (vec.data[i] > max)
        {
            max2 = max;
            max = vec.data[i];
        }
        else if (vec.data[i] > max2)
        {
            max2 = vec.data[i];
        }
    }
    return max2;
}
