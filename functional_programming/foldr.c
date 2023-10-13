#include "functional_programming.h"

int foldr(int *array, size_t len, int (*func)(int, int))
{
    if (len == 0)
        return 0;
    return (*func)(*array, foldr(array + 1, len - 1, func));
}
