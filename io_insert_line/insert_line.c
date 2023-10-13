#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>

static int extend_file(int n, int *line, const char *content, FILE *f_write)
{
    int wr;
    while (*line < n)
    {
        wr = fputs("\n", f_write);
        if (wr < 0)
            return -1;
        *line += 1;
    }
    wr = fputs(content, f_write);
    if (wr < 0)
        return -1;
    return 0;
}

int insert_line(const char *file_in, const char *file_out, const char *content,
                int n)
{
    FILE *f_read = fopen(file_in, "r");
    FILE *f_write = fopen(file_out, "w");
    if (!f_write || !f_read)
        return -1;
    size_t buffSize = 0;
    char *buff = NULL;
    ssize_t r;
    int line = 0;
    int replaced = 0;
    while ((r = getline(&buff, &buffSize, f_read)) != -1)
    {
        int wr;
        if (buff == NULL)
            return -1;
        if (line++ == n)
        {
            wr = fputs(content, f_write);
            replaced = 1;
            break;
        }
        else
            wr = fputs(buff, f_write);
        if (wr < 0)
            return -1;
    }
    if (replaced == 0 && extend_file(n, &line, content, f_write) == -1)
        return -1;
    free(buff);
    fclose(f_read);
    fclose(f_write);
    return line;
}
