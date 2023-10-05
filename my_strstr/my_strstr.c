#include "my_strstr.h"

int my_strcmp(const char *ha, const char *ne)
{
    size_t i = 0;
    for (; ha[i] == ne[i] && ha[i] != 0 && ne[i] != 0; i++)
        continue;
    if (ne[i] == 0)
        return 1;
    return 0;
}

int my_strstr(const char *haystack, const char *needle)
{
    for (int i = 0; haystack[i] != 0; i++)
    {
        if (my_strcmp(haystack + i, needle) == 1)
        {
            return i;
        }
    }
    return -1;
}
