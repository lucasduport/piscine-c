#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

struct vector *vector_append(struct vector *v, int elt)
{
    if (v == NULL)
        return NULL;
    else if (v->size + 1 > v->capacity)
    {
        v = vector_resize(v, v->size + 1);
        if (v == NULL)
            return NULL;
    }
    v->data[v->size] = elt;
    v->size++;
    return v;
}

void vector_print(const struct vector *v)
{
    if (v != NULL)
    {
        if (v->size > 0)
        {
            printf("%d", v->data[0]);
        }
        for (size_t i = 1; i < v->size;)
            printf(",%d", v->data[i++]);
    }
    printf("\n");
}

struct vector *vector_reset(struct vector *v, size_t n)
{
    if (v == NULL)
        return NULL;
    v->size = 0;
    v->data = realloc(v->data, sizeof(int) * n);
    if (v->data == NULL)
        return NULL;
    v->capacity = n;
    return v;
}

struct vector *vector_insert(struct vector *v, size_t i, int elt)
{
    if (i > v->size)
        return NULL;
    else if (i == v->size)
        return vector_append(v, elt);
    else
    {
        if (v->size + 1 > v->capacity)
        {
            v = vector_resize(v, v->size + 1);
            if (v == NULL)
                return NULL;
        }
        int tmp = v->data[i];
        v->data[i] = elt;
        v->size++;
        for (size_t j = i + 1; j < v->size; j++)
        {
            int tmp2 = v->data[j];
            v->data[j] = tmp;
            tmp = tmp2;
        }
        return v;
    }
}

struct vector *vector_remove(struct vector *v, size_t i)
{
    if (i >= v->size)
        return NULL;
    else
    {
        if (v->size - 1 < v->capacity / 2)
        {
            v = vector_resize(v, v->capacity / 2);
            if (v == NULL)
                return NULL;
        }
        int s = v->size;
        for (int j = i + 1; j > 0 && j < s; j++)
        {
            v->data[j - 1] = v->data[j];
        }
        v->size--;
        return v;
    }
}
