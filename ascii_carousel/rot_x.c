#include <stddef.h>

void rot_x(char *s, int x)
{
    size_t i = 0;
    for (; s[i] != 0; i++)
    {
        char c = s[i];
        if (c >= 'A' && c <= 'Z')
        {
            s[i] = (c - 'A' + x) % 26 + 'A';
        }
        if (c >= 'a' && c <= 'z')
        {
            s[i] = (c - 'a' + x) % 26 + 'a';
        }
    }
}
