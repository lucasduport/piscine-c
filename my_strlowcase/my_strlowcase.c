#include <stddef.h>

void my_strlowcase(char *s)
{
    for (size_t i = 0; s[i] != 0; i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] -= ('A' - 'a');
}
