#include "is_set.h"

unsigned int is_set(unsigned int value, unsigned char n)
{
    unsigned int test = 1 << (n - 1);

    return ((value & test) == 0) ? 0 : 1;
}
