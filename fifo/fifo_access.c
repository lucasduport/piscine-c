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
    newT->next = fifo->tail;
    fifo->tail = newT;
    if (fifo->head == NULL)
        fifo->head = newT;
    fifo->size++;
}

int fifo_head(struct fifo *fifo)
{
    return fifo->head->data;
}

void fifo_pop(struct fifo *fifo)
{
    if (fifo->size == 0)
        return;
    if (fifo->size == 1)
    {
        free(fifo->head);
        fifo->head = NULL;
        fifo->tail = NULL;
        fifo->size = 0;
        return;
    }
    struct list *h = fifo->tail;
    for (; h->next != fifo->head; h = h->next)
        continue;
    fifo->head = h;
    free(h->next);
    h->next = NULL;
    fifo->size--;
    if (fifo->size == 1)
        fifo->tail = fifo->head;
}

void fifo_print(const struct fifo *fifo)
{
    int *values = malloc(sizeof(int) * fifo->size);
    struct list *l = fifo->tail;
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
