#include "my_atoi.h"

int my_pow(int n, int p)
{
    if (p == 0)
        return 1;
    return n * my_pow(n, p - 1);
}
int my_atoi(const char *str)
{
    int nbDigits = 0;
    int sign = 1;
    int nbSign = 0;
    int len = 0;
    for (; str[len] != 0; len++)
        continue;
    int res = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        if (str[i] == ' ')
        {
            if (nbDigits != 0 || nbSign != 0)
                return 0;
        }
        else if (str[i] == '-' || str[i] == '+')
        {
            if (nbSign > 0)
                return 0;
            sign = (str[i] == '+') ? 1 : -1;
            nbSign++;
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            res += (str[i] - '0') * my_pow(10, nbDigits);
            nbDigits++;
        }
    }
    return sign * res;
}
