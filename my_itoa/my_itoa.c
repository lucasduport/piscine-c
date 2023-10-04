#include "my_itoa.h"

#include <stddef.h>

char *my_itoa(int value, char *s)
{
    if (value == 0)
    {
        s[0] = '0';
        s[1] = 0;
        return s;
    }
    size_t len = 0;
    if (value < 0)
    {
        s[0] = '-';
        len++;
    }

    int copy = (value < 0) ? -value : value;
    for (; copy != 0; copy /= 10)
        s[len++] = (copy % 10) + '0';

    size_t padd = (value < 0) ? 1 : 0;
    size_t j = padd;
    for (; j < (len) / 2; j++)
    {
        char tmp = s[j];
        s[j] = s[len - 1 + padd - j];
        s[len - 1 + padd - j] = tmp;
    }
    s[len] = 0;
    return s;
}
