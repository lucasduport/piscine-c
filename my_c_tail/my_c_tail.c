#include "my_c_tail.h"

#include <stdlib.h>
#include <unistd.h>

#include "sys/types.h"

void stdintail(unsigned int n)
{
    char buff[] = " ";
    int i = 0;
    unsigned int indexN = 0;
    int *newLines = malloc(sizeof(int) * (indexN + 1));
    char *s = NULL;
    while (read(STDIN_FILENO, buff, 1) != 0)
    {
        if (buff[0] == '\n')
        {
            newLines = realloc(newLines, sizeof(int) * (indexN + 1));
            newLines[indexN++] = i;
        }
        s = realloc(s, sizeof(char) * (i + 1));
        s[i++] = buff[0];
    }
    int res;
    if (indexN == 0 || n >= indexN)
        res = 0;
    else
        res = newLines[indexN - n - 1] + 1;
    write(STDOUT_FILENO, s + res, i - res);
    free(newLines);
    free(s);
}
