#include <stddef.h>

unsigned array_min(const int arr[], unsigned start, unsigned size)
{
    int mini = arr[start];
    unsigned miniInd = start;
        for (size_t i = start; i < size; i++)
        {
            if (arr[i] < mini)
            {
                mini = arr[i];
                miniInd = i;
            }
        }
    return miniInd;
}

void selection_sort(int arr[], unsigned size)
{
    for (size_t i = 0; i < size; i++)
    {
        unsigned j = array_min(arr, i, size);
        if (i != j)
        {
            unsigned temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}
