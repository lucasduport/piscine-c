#include <stdlib.h>

#include "vector.h"

struct vector *vector_init(size_t n)
{
    struct vector *new = malloc(sizeof(struct vector));
    if (new == NULL)
        return NULL;
    new->size = 0;
    new->capacity = n;
    new->data = malloc(sizeof(int) * n);
    if (new->data == NULL)
    {
        free(new);
        return NULL;
    }
    return new;
}

void vector_destroy(struct vector *v)
{
    if (v == NULL)
        return;
    if (v->data != NULL)
        free(v->data);
    free(v);
}

struct vector *vector_resize(struct vector *v, size_t n)
{
    if (v == NULL)
        return NULL;
    if (n == v->capacity)
        return v;
    v->data = realloc(v->data, sizeof(int) * n);
    if (v->data == NULL)
        return NULL;
    if (v->size > n)
        v->size = n;
    v->capacity = n;
    return v;
}
