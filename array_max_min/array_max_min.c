#include "array_max_min.h"

void array_max_min(int tab[], size_t len, int *max, int *min)
{
    *max = *tab;
    *min = *tab;
    for(size_t i=0; i < len; i++)
    {
        if (tab[i] > *max)
            *max = tab[i];
        if (*min > tab[i])
            *min = tab[i];
    }
}
