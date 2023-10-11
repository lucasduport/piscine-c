#include "bst.h"

#include "bst_static.h"

struct bst_node *create_node(int value)
{
    struct bst_node *b = malloc(sizeof(struct bst_node));
    b->left = NULL;
    b->right = NULL;
    b->data = value;
    return b;
}

struct bst_node *add_node(struct bst_node *tree, int value)
{
    if (tree == NULL)
        return create_node(value);
    else if (tree->data < value)
        tree->right = add_node(tree->right, value);
    else if (tree->data >= value)
        tree->left = add_node(tree->left, value);
    return tree;
}

struct bst_node *get_min(struct bst_node *t)
{
    if (t == NULL)
        return NULL;
    for (; t->left != NULL; t = t->left)
        continue;
    return t;
}

struct bst_node *delete_node(struct bst_node *tree, int value)
{
    struct bst_node *tmp;
    if (tree == NULL)
        return NULL;
    else if (value < tree->data)
        tree->left = delete_node(tree->left, value);
    else if (value > tree->data)
        tree->right = delete_node(tree->right, value);
    else if (tree->right == NULL)
    {
        tmp = tree->left;
        free(tree);
        return tmp;
    }
    else if (tree->left == NULL)
    {
        tmp = tree->right;
        free(tree);
        return tmp;
    }
    tmp = get_min(tree->right);
    tree->data = tmp->data;
    tree->right = delete_node(tree->right, tmp->data);
    return tree;
}

const struct bst_node *find(const struct bst_node *tree, int value)
{
    if (tree == NULL)
        return NULL;
    else if (value < tree->data)
        return find(tree->left, value);
    else if (value > tree->data)
        return find(tree->right, value);
    else
        return tree;
}

void free_bst(struct bst_node *tree)
{
    if (tree == NULL)
        return;
    struct bst_node *l = tree->left;
    struct bst_node *r = tree->right;
    free(tree);
    free_bst(l);
    free_bst(r);
}
