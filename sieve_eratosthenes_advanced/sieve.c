#include <stdio.h>
#include <stdlib.h>

void sieve(int n)
{
    if (n <= 2)
        return;
    int cnt = n / 2;
    char *marked = calloc(n / 2 + 1, sizeof(char));
    for (int i = 3; i * i <= n; i += 2)
    {
        if (marked[i / 2] == 0)
        {
            for (int j = 3 * i; j < n; j += i * 2)
            {
                if (marked[j / 2] == 0)
                    cnt--;
                marked[j / 2] = 1;
            }
        }
    }
    printf("%d\n", cnt);
    free(marked);
}
