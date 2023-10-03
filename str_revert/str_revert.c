#include "str_revert.h"

void str_revert(char str[])
{
    size_t len = 0;
    for (size_t i = 0; str[i] != 0; i++)
        len++;
    for (size_t i = 0; i < len / 2; i++)
    {
        char tmp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = tmp;
    }
}
