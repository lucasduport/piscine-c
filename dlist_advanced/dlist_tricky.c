#include <stdlib.h>

#include "dlist.h"

void dlist_map_square(struct dlist *list)
{
    struct dlist_item *i = list->head;
    for (; i != NULL; i = i->next)
        i->data *= i->data;
}

void dlist_reverse(struct dlist *list)
{
    struct dlist_item *i = list->head;
    for (; i != NULL;)
    {
        struct dlist_item *iNext = i->next;
        i->next = i->prev;
        i->prev = iNext;
        i = iNext;
    }
    struct dlist_item *tmp = list->head;
    list->head = list->tail;
    list->tail = tmp;
}

void reset_dlist(struct dlist *d)
{
    d->size = 0;
    d->tail = NULL;
    d->head = NULL;
}

struct dlist *dlist_split_at(struct dlist *list, size_t index)
{
    if (index > list->size)
        return NULL;
    struct dlist *new = malloc(sizeof(struct dlist));
    if (new == NULL)
        return NULL;
    reset_dlist(new);
    if (list->size == 0 || index == list->size)
        return new;
    else if (index == 0)
    {
        new->size = list->size;
        new->head = list->head;
        new->tail = list->tail;
        reset_dlist(list);
        return new;
    }
    struct dlist_item *i = list->head;
    for (size_t j = index; j != 0; j--, i = i->next)
        continue;
    new->tail = list->tail;
    list->tail = i->prev;
    if (list->tail != NULL)
        list->tail->next = NULL;
    new->size = list->size - index;
    list->size = index;
    new->head = i;
    if (new->head != NULL)
        new->head->prev = NULL;
    return new;
}

void dlist_concat(struct dlist *list1, struct dlist *list2)
{
    if (list2->size == 0)
        return;
    if (list1->size == 0)
    {
        list1->head = list2->head;
        list1->tail = list2->tail;
    }
    else if (list1->tail != NULL)
    {
        list1->tail->next = list2->head;
        if (list2->head != NULL)
            list2->head->prev = list1->tail;
        list1->tail = list2->tail;
    }
    list1->size += list2->size;
    list2->size = 0;
    list2->head = NULL;
    list2->tail = NULL;
}
