#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>

int merge_files(const char *file_1, const char *file_2)
{
    FILE *f_read = fopen(file_2, "r");
    if (f_read == NULL)
        return -1;
    FILE *f_write = fopen(file_1, "a");
    if (f_write == NULL)
        return -1;
    size_t buffSize = 20;
    char *buff = malloc(sizeof(char) * buffSize);
    ssize_t r;
    while ((r = getline(&buff, &buffSize, f_read)) != -1)
    {
        if (buff == NULL)
            return -1;
        int wr = fputs(buff, f_write);
        if (wr < 0)
            return -1;
    }
    free(buff);
    return 0;
}
