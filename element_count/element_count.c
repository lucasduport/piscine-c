#include "element_count.h"

size_t element_count(int *begin, int *end)
{
    size_t count = 0;
    for (; begin + count != end; count++)
        continue;
    return count;
}
