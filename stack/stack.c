#include "stack.h"

#include <stdlib.h>

struct stack *stack_push(struct stack *s, int e)
{
    struct stack *elt = malloc(sizeof(struct stack));
    if (elt == NULL)
        return s;
    elt->data = e;
    elt->next = s;
    return elt;
}

struct stack *stack_pop(struct stack *s)
{
    if (s == NULL)
        return NULL;
    struct stack *res = s->next;
    free(s);
    return res;
}

int stack_peek(struct stack *s)
{
    return s->data;
}
