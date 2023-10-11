#include <stdlib.h>

#include "dlist.h"

void dlist_sort(struct dlist *list)
{
    struct dlist *sorted = dlist_init();
    struct dlist_item *i = list->head;
    for (; i != NULL; i = i->next)
        dlist_add_sort(sorted, i->data);
    dlist_clear(list);
    list->size = sorted->size;
    list->head = sorted->head;
    list->tail = sorted->tail;
    free(sorted);
}

void dlist_merge(struct dlist *list1, struct dlist *list2)
{
    dlist_concat(list1, list2);
    dlist_sort(list1);
}

unsigned int min(unsigned int a, unsigned int b)
{
    return (a < b) ? a : b;
}

static unsigned int cmp_val(struct dlist *d1, struct dlist *d2, size_t i1,
                            size_t i2)
{
    if (dlist_get(d1, i1) == dlist_get(d2, i2))
        return 0;
    return 1;
}

unsigned int dlist_levenshtein(struct dlist *list1, struct dlist *list2)
{
    unsigned int lenS1 = list1->size;
    unsigned int *col1 = malloc(sizeof(unsigned int) * (lenS1 + 1));
    col1[0] = 0;
    unsigned int lenS2 = list2->size;
    for (unsigned int j = 1; j <= lenS1; j++)
    {
        col1[j] = j;
    }
    for (unsigned int i = 1; i <= lenS2; i++)
    {
        col1[0] = i;
        unsigned int der_d = i - 1;
        for (unsigned int j = 1; j <= lenS1; j++)
        {
            unsigned int anc_d = col1[j];
            col1[j] = min(min(col1[j] + 1, col1[j - 1] + 1),
                          der_d + cmp_val(list1, list2, j - 1, i - 1));
            der_d = anc_d;
        }
    }
    unsigned int res = col1[lenS1];
    free(col1);
    return res;
}
