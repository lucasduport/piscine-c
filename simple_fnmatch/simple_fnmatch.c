#include "simple_fnmatch.h"

#include <stddef.h>

int simple_fnmatch(const char *pattern, const char *string)
{
    int i = 0;
    int j = 0;
    while (1)
    {
        if (pattern[j] == 0)
        {
            if (string[i] == 0)
                return 0;
            return 1;
        }
        else if (pattern[j++] == '*')
        {
            while (pattern[j] != 0 && pattern[j] == '*')
                j++;
            if (pattern[j] == 0)
                return 0;
            while (string[i] != 0)
            {
                if (!simple_fnmatch(pattern + j, string + i))
                    return 0;
                i++;
            }
            return 1;
        }
        else if (pattern[--j] == '?')
        {
            if (string[i++] == 0)
                return 1;
        }
        else
        {
            if (pattern[j] == '\\')
            {
                if (pattern[j++] == 0)
                    j--;
            }
            if (string[i++] != pattern[j])
                return 1;
        }
        j++;
    }
    return 1;
}
