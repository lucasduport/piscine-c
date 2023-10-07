#include <stdlib.h>

#include "fifo.h"

struct fifo *fifo_init(void)
{
    struct fifo *res = malloc(sizeof(struct fifo));
    if (res == NULL)
        return NULL;
    res->tail = NULL;
    res->head = NULL;
    res->size = 0;

    return res;
}

void fifo_clear(struct fifo *fifo)
{
    size_t s = fifo->size;
    for (size_t i = 0; i < s; i++)
    {
        fifo_pop(fifo);
    }
}

void fifo_destroy(struct fifo *fifo)
{
    fifo_clear(fifo);
    free(fifo);
}
