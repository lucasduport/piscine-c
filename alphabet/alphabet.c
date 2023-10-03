#include <stdio.h>

void alphabet()
{
    putchar('a');
    for (int i = 1; i < 26; i++)
    {
        putchar(' ');
        char toPrint = 'a' + i;
        putchar(toPrint);
    }
    putchar('\n');
}

int main(void)
{
    alphabet();
}
