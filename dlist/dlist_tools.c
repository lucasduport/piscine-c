#include <assert.h>
#include <stdlib.h>

#include "dlist.h"

int dlist_get(const struct dlist *list, size_t index)
{
    if (index >= list->size)
        return -1;
    struct dlist_item *l = list->head;
    if (index == 0)
        return l->data;
    else if (index > list->size / 2)
    {
        for (size_t j = 0; j < index; l = l->next, j++)
            continue;
    }
    else
    {
        l = list->tail;
        index = list->size - index - 1;
        for (size_t j = 0; j < index; l = l->prev, j++)
            continue;
    }
    if (l != NULL)
        return l->data;
    return -1;
}

struct dlist_item *get_at(struct dlist *list, size_t index)
{
    struct dlist_item *l = list->head;
    if (index == 0)
    {
        index = 0;
    }
    else if (index > list->size / 2)
    {
        for (size_t j = 0; j < index; l = l->next, j++)
            continue;
    }
    else
    {
        l = list->tail;
        index = list->size - index - 1;
        for (size_t j = 0; j < index; l = l->prev, j++)
            continue;
    }
    return l;
}

int dlist_insert_at(struct dlist *list, int element, size_t index)
{
    assert(element >= 0);
    if (index > list->size || list == NULL)
        return -1;
    struct dlist_item *l = get_at(list, index);
    if (l == list->head)
        return dlist_push_front(list, element);
    else if (l == NULL)
        return dlist_push_back(list, element);
    struct dlist_item *new = malloc(sizeof(struct dlist_item));
    new->next = NULL;
    new->prev = NULL;
    new->prev = l->prev;
    if (l->prev != NULL)
        l->prev->next = new;
    l->prev = new;
    new->next = l;
    new->data = element;
    list->size++;
    return 1;
}

int dlist_find(const struct dlist *list, int element)
{
    if (list == NULL || list->head == NULL)
        return -1;
    struct dlist_item *d = list->head;
    size_t i = 0;
    for (; d != NULL && d->data != element; d = d->next, i++)
        continue;
    if (d == NULL)
        return -1;
    return i;
}

int dlist_remove_at(struct dlist *list, size_t index)
{
    if (index > list->size || list == NULL)
        return -1;
    struct dlist_item *l = get_at(list, index);
    if (l != NULL)
    {
        if (l->prev != NULL)
            l->prev->next = l->next;
        if (l->next != NULL)
            l->next->prev = l->prev;
        int res = l->data;
        if (index == 0)
            list->head = l->next;
        if (index == list->size - 1)
            list->tail = l->prev;
        free(l);
        list->size--;
        return res;
    }
    return -1;
}

void dlist_clear(struct dlist *list)
{
    struct dlist_item *i = list->head;
    for (; i != NULL;)
    {
        struct dlist_item *n = i->next;
        free(i);
        i = n;
    }
}
