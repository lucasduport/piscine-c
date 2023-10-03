#include <stdio.h>

static void print(char symbol, unsigned times)
{
    for (unsigned i = 0; i < times; i++)
    {
        putchar(symbol);
    }
}

int pine(unsigned n)
{
    for (unsigned i = 0; i < n; i++)
    {
        print(' ', n - 1 - i);
        print('*', 2 * i + 1);
        putchar('\n');
    }
    for (unsigned i = 0; i < n / 2; i++)
    {
        print(' ', n - 1);
        putchar('*');
        putchar('\n');
    }
    if (n < 3)
        return 1;
    return 0;
}
