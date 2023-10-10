#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>

static int my_pow(int n, int p)
{
    if (p == 0)
        return 1;
    return n * my_pow(n, p - 1);
}

static int isInvalid(const char *str)
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

static int my_atoi(const char *str)
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

static void rot_x(char *s, int x, size_t size)
{
    if (s == NULL)
        return;
    size_t i = 0;
    for (; i <= size; i++)
    {
        char c = s[i];
        if (c >= 'A' && c <= 'Z')
        {
            s[i] = ((c - 'A' + x) % 26 + 26) % 26 + 'A';
        }
        if (c >= 'a' && c <= 'z')
        {
            s[i] = ((c - 'a' + x) % 26 + 26) % 26 + 'a';
        }
        if (c >= '0' && c <= '9')
        {
            s[i] = ((c - '0' + x) % 10 + 10) % 10 + '0';
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc == 1)
        return 0;
    int key = my_atoi(argv[1]);
    char buff[21] = { 0 };
    size_t buffSize = 20;
    while (1)
    {
        ssize_t recupRead = read(STDIN_FILENO, buff, buffSize);
        if (recupRead == -1)
            return 1;
        if (recupRead == 0)
            break;
        rot_x(buff, key, recupRead);
        write(STDOUT_FILENO, buff, recupRead);
    }
    return 0;
}
