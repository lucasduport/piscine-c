#include "list.h"

#include <stdlib.h>
#include <string.h>

struct list *list_prepend(struct list *list, const void *value,
                          size_t data_size)
{
    struct list *new = malloc(sizeof(struct list));
    if (new == NULL)
        return NULL;
    new->next = list;
    memcpy(new->data, value, data_size);
    return new;
}

size_t list_length(struct list *list)
{
    size_t len = 0;
    for (; list != NULL; len++, list = list->next)
        continue;
    return len;
}

void list_destroy(struct list *list)
{
    for (; list != NULL;)
    {
        struct list *tmp = list->next;
        free(list);
        list = tmp;
    }
}
