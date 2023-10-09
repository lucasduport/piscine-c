#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

struct dlist *dlist_init(void)
{
    struct dlist *dl = malloc(sizeof(struct dlist));
    if (dl == NULL)
        return NULL;
    dl->size = 0;
    dl->head = NULL;
    dl->tail = NULL;
    return dl;
}

int dlist_push_front(struct dlist *list, int element)
{
    assert(element >= 0);
    struct dlist_item *new = malloc(sizeof(struct dlist_item));
    if (new == NULL)
        return 0;
    new->prev = NULL;
    if (list->head != NULL)
        list->head->prev = new;
    new->next = list->head;
    new->data = element;
    list->head = new;
    list->size++;
    if (list->size == 1)
        list->tail = list->head;
    return 1;
}

void dlist_print(const struct dlist *list)
{
    if (list == NULL || list->head == NULL)
        return;
    for (struct dlist_item *d = list->head; d != NULL; d = d->next)
    {
        printf("%d\n", d->data);
    }
}

int dlist_push_back(struct dlist *list, int element)
{
    assert(element >= 0);
    struct dlist_item *new = malloc(sizeof(struct dlist_item));
    if (new == NULL)
        return 0;
    if (list->tail != NULL)
        list->tail->next = new;
    new->prev = list->tail;
    new->next = NULL;
    new->data = element;
    list->tail = new;
    list->size++;
    if (list->size == 1)
        list->head = list->tail;
    return 1;
}

size_t dlist_size(const struct dlist *list)
{
    return list->size;
}
