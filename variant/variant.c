#include "variant.h"

#include <stdio.h>

void variant_display(const struct variant *e)
{
    switch (e->type)
    {
    case TYPE_INT:
        printf("%d\n", e->value.int_v);
        break;
    case TYPE_CHAR:
        printf("%c\n", e->value.char_v);
        break;
    case TYPE_FLOAT:
        printf("%f\n", e->value.float_v);
        break;
    case TYPE_STRING:
        printf("%s\n", e->value.str_v);
        break;
    default:
        break;
    }
}

static bool my_strcmp(const char *s1, const char *s2)
{
    size_t i = 0;
    for (; s1[i] == s2[i] && s1[i] != 0 && s2[i] != 0; i++)
        continue;
    if (s1[i] == s2[i] && s1[i] == 0)
        return true;
    return false;
}

bool variant_equal(const struct variant *left, const struct variant *right)
{
    if (left->type == right->type)
    {
        if (left->type == TYPE_INT)
            return left->value.int_v == right->value.int_v;
        if (left->type == TYPE_FLOAT)
            return left->value.float_v == right->value.float_v;
        if (left->type == TYPE_CHAR)
            return left->value.char_v == right->value.char_v;
        if (left->type == TYPE_STRING)
            return my_strcmp(left->value.str_v, right->value.str_v);
    }
    return false;
}

int variant_find(const struct variant *array, size_t len, enum type type,
                 union type_any value)
{
    struct variant toCompare = { .type = type, .value = value };
    for (size_t i = 0; i < len; i++)
    {
        if (variant_equal(&array[i], &toCompare))
            return i;
    }
    return -1;
}

float variant_sum(const struct variant *array, size_t len)
{
    float res = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (array->type == TYPE_FLOAT)
            res += array->value.float_v;
        if (array->type == TYPE_INT)
            res += array->value.int_v;
    }
    return res;
}
