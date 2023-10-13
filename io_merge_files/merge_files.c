#include <stdio.h>

#define _POSIX_C_SOURCE 200809L

int merge_files(const char *file_1, const char *file_2)
{
    FILE *f_read = fopen(file_2, "r");
    if (f_read == NULL)
        return -1;
    FILE *f_write = fopen(file_1, "a");
    if (f_write == NULL)
        return -1;
    char buff[20] = "";
    size_t buffSize = 20;
    size_t r;
    while ((r = fread(buff, sizeof(char), buffSize, f_read)) != 0)
    {
        size_t wr = fwrite(buff, sizeof(char), r, f_write);
        if (wr == 0)
            return -1;
    }
    return 0;
}
