#include "bst_static.h"

#include <stdlib.h>

static void all_null(struct bst *b, size_t start)
{
    if (!b || !b->data)
        return;
    for (size_t i = start; i < b->capacity; i++)
        b->data[i] = NULL;
    return;
}

struct bst *init(size_t capacity)
{
    struct bst *b = malloc(sizeof(struct bst));
    if (b == NULL)
        return NULL;
    b->size = 0;
    b->capacity = capacity;
    b->data = malloc(sizeof(struct value *) * capacity);
    all_null(b, 0);
    if (b->data == NULL)
    {
        free(b);
        return NULL;
    }
    return b;
}

static void add_rec(struct bst *tree, int value, size_t index)
{
    if (index >= tree->capacity)
    {
        tree->data =
            realloc(tree->data, sizeof(struct value *) * tree->capacity * 2);
        if (tree->data == NULL)
            return;
        tree->capacity *= 2;
        all_null(tree, tree->capacity / 2);
        add_rec(tree, value, index);
    }
    else if (tree->data[index] == NULL)
    {
        tree->data[index] = malloc(sizeof(struct value));
        if (tree->data[index] == NULL)
            return;
        tree->data[index]->val = value;
        return;
    }
    else if (tree->data[index]->val < value)
        add_rec(tree, value, 2 * index + 2);
    else if (tree->data[index]->val >= value)
        add_rec(tree, value, 2 * index + 1);
    return;
}

void add(struct bst *tree, int value)
{
    add_rec(tree, value, 0);
    tree->size++;
}

int search(struct bst *tree, int value)
{
    if (tree == NULL || tree->size == 0 || tree->data == NULL)
        return -1;
    for (size_t i = 0; i < tree->capacity; i++)
    {
        if (tree->data[i] && tree->data[i]->val == value)
            return i;
    }
    return -1;
}

void bst_free(struct bst *tree)
{
    if (tree == NULL)
        return;
    if (tree->data != NULL)
    {
        for (size_t i = 0; i < tree->capacity; i++)
        {
            if (tree->data[i] != NULL)
                free(tree->data[i]);
        }
        free(tree->data);
    }
    free(tree);
}
