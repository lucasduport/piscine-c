#include <stdio.h>
#include <stdlib.h>

void sieve(int n)
{
    unsigned cnt = 0;
    if (n <= 1)
        return;
    if (n > 2)
        cnt++;
    char *marked = calloc(n / 2, sizeof(char));
    for (int i = 3; i * i <= n; i += 2)
    {
        if (marked[i / 2] == 0)
        {
            cnt++;
            for (int j = i + 2; j * j <= n; j += 2)
            {
                if (j % i == 0)
                {
                    marked[j / 2] = 1;
                }
            }
        }
    }
    printf("%u\n", cnt);
    free(marked);
}
