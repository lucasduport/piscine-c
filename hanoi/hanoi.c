#include <stdio.h>

void hanoi_rec(unsigned n, char *t1, char *t3, char *t2)
{
    if (n > 0)
    {
        hanoi_rec(n - 1, t1, t2, t3);
        printf("%c->%c\n", *t1, *t3);
        hanoi_rec(n - 1, t2, t3, t1);
    }
}

void hanoi(unsigned n)
{
    char t1 = '1';
    char t2 = '2';
    char t3 = '3';

    hanoi_rec(n, &t1, &t3, &t2);
}
