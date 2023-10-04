#include "bsearch.h"

int *binary_search(int *begin, int *end, int elt)
{
    int *left = begin;
    int *right = end - 1;
    int *piv = begin;
    while (left <= right)
    {
        piv = left + (right - left) / 2;
        if (elt < *piv)
            right = piv - 1;
        else if (elt > *piv)
            left = piv + 1;
        else
            return piv;
    }
    return left;
}
