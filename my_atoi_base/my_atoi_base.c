#include "my_atoi_base.h"

int my_pow(int n, int p)
{
    if (p == 0)
        return 1;
    return n * my_pow(n, p - 1);
}

int isInBase(char c, const char *base)
{
    for (size_t check = 0; base[check] != 0; check++)
    {
        if (base[check] == c)
        {
            return 1;
        }
    }
    return 0;
}

int isInvalid(const char *str, const char *base)
{
    int i = 0;
    int num = 0;
    int sign = 0;
    for (; str[i] != 0; i++)
    {
        if (isInBase(str[i], base) == 1)
            num = 1;
        else if (str[i] == '+' || str[i] == '-')
        {
            if (sign == 1)
                return 0;
            sign = 1;
        }
        else if (str[i] == ' ' && num + sign == 0)
            continue;
        else
            return 0;
    }
    return 1;
}

size_t my_strlen(const char *s)
{
    size_t count = 0;
    for (size_t i = 0; s[i] != 0; i++)
    {
        count++;
    }
    return count;
}

size_t getPos(char c, const char *base)
{
    size_t i = 0;
    for (; base[i] != c; i++)
        continue;
    return i;
}

int my_atoi_base(const char *str, const char *base)
{
    int len = 0;
    for (; str[len] != 0; len++)
        continue;
    if (isInvalid(str, base) == 0)
    {
        return 0;
    }
    int baseInt = my_strlen(base);
    int res = 0;
    int nbDigits = 0;
    int sign = 1;
    for (int i = len - 1; i >= 0; i--)
    {
        if (str[i] == '-' || str[i] == '+')
        {
            sign = (str[i] == '+') ? 1 : -1;
        }
        else if (str[i] != ' ')
        {
            res += (getPos(str[i], base)) * my_pow(baseInt, nbDigits);
            nbDigits++;
        }
    }
    return sign * res;
}
