#include <stdio.h>

int binary_search(const int vec[], int size, int elt)
{
    int left = 0;
    int right = size - 1;
    while (left <= right)
    {
        int piv = left + (right - left) / 2;
        if (elt < vec[piv])
            right = piv - 1;
        else if (elt > vec[piv])
            left = piv + 1;
        else
            return piv;
    }
    return -1;
}
