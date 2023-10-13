#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>

int count_words(const char *file_in)
{
    if (!file_in)
        return -1;
    FILE *f_read = fopen(file_in, "r");
    if (!f_read)
        return -1;
    char c;
    int i = 0;
    int lastLetter = -2;
    int count = 0;
    while ((c = fgetc(f_read)) != -1)
    {
        if (c > ' ')
        {
            if (lastLetter != i - 1)
                count++;
            lastLetter = i;
        }
        i++;
    }
    fclose(f_read);
    return count;
}
