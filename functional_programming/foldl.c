#include "functional_programming.h"

int foldl(int *array, size_t len, int (*func)(int, int))
{
    if (len == 0)
        return *array;
    return (*func)(foldl(array - 1, len - 1, func), *array);
}
