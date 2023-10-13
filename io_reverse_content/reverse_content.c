#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>

int reverse_content(const char *file_in, const char *file_out)
{
    FILE *f_read = fopen(file_in, "r");
    if (f_read == NULL)
        return -1;
    FILE *f_write = fopen(file_out, "w");
    if (f_write == NULL)
        return -1;
    char c;
    size_t count = 0;
    off_t off = fseek(f_read, -++count, SEEK_END);
    while (off != -1 && (c = fgetc(f_read)) != 0)
    {
        int wr = fputc(c, f_write);
        if (wr < 0)
            return -1;
        off = fseek(f_read, -++count, SEEK_END);
    }
    fclose(f_read);
    fclose(f_write);
    return 0;
}
