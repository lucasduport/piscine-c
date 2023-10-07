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
    newT->data = elt;
    newT->next = fifo->head;
    fifo->head = newT;
    if (fifo->tail == NULL)
        fifo->tail = newT;
    fifo->size++;
}

int fifo_head(struct fifo *fifo)
{
    return fifo->tail->data;
}

void fifo_pop(struct fifo *fifo)
{
    if (fifo->size == 0)
        return;
    if (fifo->size == 1)
    {
        free(fifo->tail);
        fifo->tail = NULL;
        fifo->head = NULL;
        fifo->tail = 0;
        return;
    }
    struct list *h = fifo->head;
    for (; h->next != fifo->tail; h = h->next)
        continue;
    fifo->tail = h;
    free(h->next);
    h->next = NULL;
    fifo->size--;
    if (fifo->size == 1)
        fifo->head = fifo->tail;
}

void fifo_print(const struct fifo *fifo)
{
    int *values = malloc(sizeof(int) * fifo->size);
    struct list *l = fifo->head;
    size_t i = 0;
    for (; l != NULL; i++, l = l->next)
    {
        values[i] = l->data;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d\n", values[j]);
    }
    free(values);
}
