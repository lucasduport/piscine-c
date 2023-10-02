#include <stddef.h>

void plus_equal(int *a, int *b)
{
    if (a == NULL || b == NULL)
        return;
    *a += *b;
}

void minus_equal(int *a, int *b)
{
    if (a == NULL || b == NULL)
        return;
    *a -= *b;
}

void mult_equal(int *a, int *b)
{
    if (a == NULL || b == NULL)
        return;
    *a *= *b;
}

int div_equal(int *a, int *b)
{
    if (a == NULL || b == NULL || *b == 0)
        return 0;
    int rem = *a % *b;
    *a /= *b;
    return rem;
}
