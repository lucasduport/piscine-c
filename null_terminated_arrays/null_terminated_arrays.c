#include "null_terminated_arrays.h"

#include <stddef.h>

static size_t get_l1(const char ***matrix)
{
    size_t len = 0;
    for (size_t i = 0; matrix[i] != NULL; i++)
        len++;
    return len;
}

static size_t get_l2(const char **matrix)
{
    size_t len = 0;
    for (size_t i = 0; matrix[i] != NULL; i++)
        len++;
    return len;
}

void reverse_matrix(const char ***matrix)
{
    size_t l1 = get_l1(matrix);
    for (size_t i = 0; i < l1; i++)
    {
        size_t l2 = get_l2(matrix[i]);
        for (size_t j = 0; j < l2 / 2; j++)
        {
            const char *tmp = matrix[i][j];
            matrix[i][j] = matrix[i][l2 - 1 - j];
            matrix[i][l2 - 1 - j] = tmp;
        }
    }
    for (size_t i = 0; i < l1 / 2; i++)
    {
        const char **tmp = matrix[i];
        matrix[i] = matrix[l1 - 1 - i];
        matrix[l1 - 1 - i] = tmp;
    }
}
