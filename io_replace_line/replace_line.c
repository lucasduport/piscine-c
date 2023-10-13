#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>

int replace_line(const char *file_in, const char *file_out, const char *content,
                 int n)
{
    FILE *f_read = fopen(file_in, "r");
    if (f_read == NULL)
        return -1;
    FILE *f_write = fopen(file_out, "w");
    if (f_write == NULL)
        return -1;
    size_t buffSize = 0;
    char *buff = NULL;
    ssize_t r;
    int line = 0;
    while ((r = getline(&buff, &buffSize, f_read)) != -1)
    {
        int wr;
        if (buff == NULL)
            return -1;
        if (line == n)
            wr = fputs(content, f_write);
        else
            wr = fputs(buff, f_write);
        if (wr < 0)
            return -1;
        line++;
    }
    free(buff);
    fclose(f_read);
    fclose(f_write);
    if (n >= line)
        return 1;
    return 0;
}
