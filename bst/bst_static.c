#include "bst_static.h"

#include <stdlib.h>
struct bst *init(size_t capacity)
{
    struct bst *b = malloc(sizeof(struct bst));
    if (b == NULL)
        return NULL;
    b->size = 0;
    b->capacity = capacity;
    b->data = calloc(sizeof(struct value), capacity);
    if (b->data == NULL)
    {
        free(b);
        return NULL;
    }
    return b;
}

static void add_rec(struct bst *tree, int value, size_t index)
{
    if (tree->data[index] == NULL)
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
    if (tree->size + 1 > tree->capacity)
    {
        tree->data = realloc(tree->data, tree->capacity * 2);
        if (tree->data == NULL)
            return;
        tree->capacity *= 2;
    }
    add_rec(tree, value, 0);
}

int search(struct bst *tree, int value)
{
    if (tree == NULL || tree->size == 0 || tree->data == NULL)
        return -1;
    for (size_t i = 0; i < tree->size; i++)
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
        for (size_t i = 0; i < tree->size; i++)
        {
            if (tree->data[i] != NULL)
                free(tree->data[i]);
        }
        free(tree->data);
    }
    free(tree);
}
