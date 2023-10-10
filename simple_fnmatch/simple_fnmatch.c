#include "simple_fnmatch.h"

#include <stddef.h>

size_t my_strlen(const char *s)
{
    size_t count = 0;
    for (size_t i = 0; s[i] != 0; i++)
    {
        count++;
    }
    return count;
}

int simple_fnmatch(const char *pattern, const char *string)
{
    int i = 0;
    int j = 0;
    int escaping = -2;
    int lenP = my_strlen(pattern);
    int lenS = my_strlen(string);
    for (; i <= lenS && j < lenP;)
    {
        if (pattern[j] == '\\')
        {
            escaping = j;
            j++;
        }
        else if (pattern[j] == '?' && escaping != j - 1)
        {
            j++;
            i++;
        }
        else if (pattern[j] == '*' && escaping != j - 1)
        {
            j++;
            while (pattern[j] != 0 && (pattern[j] == '*' || pattern[j] == '?'))
                j++;
            if (pattern[j] != 0)
            {
                while (pattern[j] != 0 && string[i] != 0
                       && string[i] != pattern[j])
                    i++;
            }
            else
                return 0;
        }
        else if (string[i] != pattern[j])
            return FNM_NOMATCH;
        else
        {
            i++;
            j++;
        }
    }
    return !(j >= lenP && i >= lenS);
}
