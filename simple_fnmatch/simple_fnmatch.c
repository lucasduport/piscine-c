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
    while (1)
    {
        if (pattern[j] == 0)
            return (string[i] == 0) ? 0 : FNM_NOMATCH;
        else if (pattern[j] == '\\')
        {
            escaping = j;
            j++;
            if (pattern[j] == 0)
                j--;
        }
        else if (pattern[j] == '?' && escaping != j - 1)
        {
            // string = stringstart ?
            if (string[i] == 0)
                return FNM_NOMATCH;
            i++;
        }
        else if (pattern[j] == '*' && escaping != j - 1)
        {
            j++;
            while (pattern[j] != 0 && pattern[j] == '*')
                j++;
            // string  = string start ?
            if (pattern[j] == 0)
                return 0;
            while (string[i] != 0)
            {
                if (!simple_fnmatch(pattern + j, string + i))
                    return 0;
                i++;
            }
            return FNM_NOMATCH;
        }
        else if (string[i] != pattern[j])
            return FNM_NOMATCH;
        else
            i++;
        j++;
    }
    return FNM_NOMATCH;
}
/*
        case '*':
            c = *pattern;
            while (c == '*')
                c = *++pattern;

            if (*string == '.' && (flags & FNM_PERIOD) &&
                (string == stringstart ||
                ((flags & FNM_PATHNAME) && *(string - 1) == '/')))
                return (FNM_NOMATCH);
            if (c == EOS)
                if (flags & FNM_PATHNAME)
                    return (strchr(string, '/') == NULL ?
                        0 : FNM_NOMATCH);
                else
                    return (0);
            else if (c == '/' && flags & FNM_PATHNAME) {
                if ((string = strchr(string, '/')) == NULL)
                    return (FNM_NOMATCH);
                break;
            }
            while ((test = *string) != EOS) {
                if (!fnmatch(pattern, string, flags & ~FNM_PERIOD))
                    return (0);
                if (test == '/' && flags & FNM_PATHNAME)
                    break;
                ++string;
            }
            return (FNM_NOMATCH);
        case '\\':
            if (!(flags & FNM_NOESCAPE)) {
                if ((c = *pattern++) == EOS) {
                    c = '\\';
                    --pattern;
                }
            }
        default:
            if (c != *string++)
                return (FNM_NOMATCH);
            break;

*/

int simple_fnmatch2(const char *pattern, const char *string)
{
    int i = 0;
    int j = 0;
    int escaping = -2;
    int lenP = my_strlen(pattern);
    int lenS = my_strlen(string);
    for (; i <= lenS && j <= lenP;)
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
            while (pattern[j] != 0 && (pattern[j] == '*' || pattern[j] == '?'))
                j++;
            while (string[i] != 0 && string[i] != pattern[j])
                i++;
        }
        else if (string[i] != pattern[j])
            return FNM_NOMATCH;
        else
        {
            i++;
            j++;
        }
    }
    return (j < lenP || i < lenS);
}
