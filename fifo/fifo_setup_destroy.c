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
    if (fifo == NULL || fifo->tail == NULL)
        return;
    struct list *i = fifo->tail;
    while (i != NULL)
    {
        struct list *tmp = i->next;
        free(i);
        i = tmp;
    }
    fifo->head = NULL;
    fifo->tail = NULL;
    fifo->size = 0;
}

void fifo_destroy(struct fifo *fifo)
{
    fifo_clear(fifo);
    free(fifo);
}
