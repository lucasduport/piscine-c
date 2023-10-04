#include "my_atoi.h"

int my_pow(int n, int p)
{
    if (p == 0)
        return 1;
    return n * my_pow(n, p - 1);
}

int isInvalid(const char *str)
{
    int i = 0;
    int num = 0;
    int sign = 0;
    for (; str[i] != 0; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
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

int my_atoi(const char *str)
{
    int len = 0;
    for (; str[len] != 0; len++)
        continue;
    if (isInvalid(str) == 0)
        return 0;
    int res = 0;
    int nbDigits = 0;
    int sign = 1;
    for (int i = len - 1; i >= 0; i--)
    {
        if (str[i] == '-' || str[i] == '+')
        {
            sign = (str[i] == '+') ? 1 : -1;
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            res += (str[i] - '0') * my_pow(10, nbDigits);
            nbDigits++;
        }
    }
    return sign * res;
}
