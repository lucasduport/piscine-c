#include "my_itoa_base.h"

size_t my_strlen(const char *s)
{
    if (s == NULL)
        return 0;
    size_t count = 0;
    for (size_t i = 0; s[i] != 0; i++)
    {
        count++;
    }
    return count;
}

void str_revert(char *str)
{
    size_t len = my_strlen(str);
    for (size_t i = 0; i < len / 2; i++)
    {
        char tmp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = tmp;
    }
}

char *my_itoa_base(int n, char *s, const char *base)
{
    if (n == 0)
    {
        s[0] = base[0];
        s[1] = 0;
        return s;
    }
    int baseInt = my_strlen(base);
    int sign = 1;
    if (n < 0)
    {
        sign = -1;
        n *= -1;
    }
    int i = 0;
    for (; n != 0; n /= baseInt, i++)
    {
        s[i] = base[n % baseInt];
    }
    if (sign == -1)
        s[i++] = '-';
    s[i] = 0;
    str_revert(s);
    return s;
}
