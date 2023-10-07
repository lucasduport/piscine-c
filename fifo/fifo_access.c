#include <stdio.h>
#include <stdlib.h>

#include "fifo.h"

size_t fifo_size(struct fifo *fifo)
{
    return fifo->size;
}

void fifo_push(struct fifo *fifo, int elt)
{
    struct list *newT = malloc(sizeof(struct list));
    newT->next = NULL;
    newT->data = elt;
    if (fifo->tail == NULL)
    {
        newT->next = fifo->tail;
    }
    fifo->tail = newT;
    if (fifo->head == NULL)
        fifo->head = fifo->tail;
    fifo->size++;
}

int fifo_head(struct fifo *fifo)
{
    return fifo->head->data;
}

void fifo_pop(struct fifo *fifo)
{
    if (fifo->head == NULL)
        return;
    struct list *i = fifo->tail;
    for (; i->next != fifo->head; i = i->next)
        continue;
    struct list *toFree = fifo->head;
    fifo->head = i;
    fifo->size--;
    free(toFree);
}

void fifo_print(const struct fifo *fifo)
{
    struct list *i = fifo->head;
    for (; i != NULL; i = i->next)
    {
        printf("%d", i->data);
        if (i->next != NULL)
            putchar('\n');
    }
}
