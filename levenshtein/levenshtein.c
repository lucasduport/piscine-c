#include "levenshtein.h"

#include <stdlib.h>

size_t min(size_t a, size_t b)
{
    return (a < b) ? a : b;
}

size_t cmp_chr(char c1, char c2)
{
    return (c1 == c2) ? 0 : 1;
}

size_t len_s(const char *s)
{
    size_t i = 0;
    for (; s[i] != 0; i++)
        continue;
    return i;
}

size_t levenshtein(const char *s1, const char *s2)
{
    size_t lenS1 = len_s(s1);
    size_t *col1 = malloc(sizeof(size_t) * (lenS1 + 1));
    col1[0] = 0;
    size_t lenS2 = len_s(s2);
    for (size_t j = 1; j <= lenS1; j++)
    {
        col1[j] = j;
    }
    for (size_t i = 1; i <= lenS2; i++)
    {
        col1[0] = i;
        size_t der_d = i - 1;
        for (size_t j = 1; j <= lenS1; j++)
        {
            size_t anc_d = col1[j];
            col1[j] = min(min(col1[j] + 1, col1[j - 1] + 1),
                          der_d + cmp_chr(s1[j - 1], s2[i - 1]));
            der_d = anc_d;
        }
    }
    size_t res = col1[lenS1];
    free(col1);
    return res;
}
