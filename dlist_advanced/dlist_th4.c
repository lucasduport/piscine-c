#include <stdlib.h>

#include "dlist.h"

void dlist_shift(struct dlist *list, int offset)
{
    if (list == NULL)
        return;
    int s = list->size;
    int newOffset = (offset % s + s) % s;
    struct dlist_item *l = list->head;
    for (int i = 0; i < s - newOffset - 1; i++, l = l->next)
        continue;
    struct dlist_item *rest = NULL;
    if (l != NULL)
    {
        rest = l->next;
        l->next = NULL;
        list->tail = l;
    }
    if (rest != NULL)
    {
        struct dlist_item *j = rest;
        for (; j->next != NULL; j = j->next)
            continue;
        if (list->head != NULL)
            list->head->prev = j;
        j->next = list->head;
        list->head = rest;
    }
}

int dlist_add_sort(struct dlist *list, int element)
{
    if (element < 0 || list == NULL)
        return -1;
    struct dlist_item *l = list->head;
    size_t i = 0;
    for (; l != NULL && l->data < element; i++, l = l->next)
        continue;
    return dlist_insert_at(list, element, i);
}

int dlist_remove_eq(struct dlist *list, int element)
{
    int index = dlist_find(list, element);
    if (index == -1)
        return -1;
    return dlist_remove_at(list, index);
}

struct dlist *dlist_copy(const struct dlist *list)
{
    if (list == NULL)
        return NULL;
    struct dlist *new = dlist_init();
    if (new == NULL)
        return NULL;
    struct dlist_item *i = list->head;
    for (; i != NULL; i = i->next)
    {
        if (dlist_push_back(new, i->data) == 0)
            return NULL;
    }
    return new;
}
