#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>

int append_file(const char *file_1, const char *content)
{
    if (file_1 == NULL)
        return -1;
    FILE *f_write = fopen(file_1, "a");
    if (fprintf(f_write, "%s", content) == -1)
        return -1;
    fclose(f_write);
    return 0;
}
