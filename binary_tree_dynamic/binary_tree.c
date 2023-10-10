#include "binary_tree.h"

#include <stdio.h>
#include <stdlib.h>

static int prof(const struct binary_tree *tree)
{
    int n = 0;
    for (int n = 0; tree != NULL; n++, tree = tree->left)
        continue;
    return n;
}

static int is_perf_rec(const struct binary_tree *tree, int n, int p)
{
    if (tree == NULL)
        return 1;
    if (tree->left == NULL && tree->right == NULL)
        return (p == n + 1);
    else if (tree->left == NULL || tree->right == NULL)
        return 0;
    if (is_perf_rec(tree->left, n + 1, p) == 0)
        return 0;
    if (is_perf_rec(tree->right, n + 1, p) == 0)
        return 0;
    return 1;
}

int is_perfect(const struct binary_tree *tree)
{
    int p = prof(tree);
    return is_perf_rec(tree, 0, p);
}

static char is_cpl_rec(const struct binary_tree *tree, size_t size, size_t i)
{
    if (tree == NULL)
        return 1;
    if (i >= size)
        return 0;
    if (is_cpl_rec(tree->left, size, 2 * i + 1) == 0)
        return 0;
    if (is_cpl_rec(tree->right, size, 2 * i + 2) == 0)
        return 0;
    return 1;
}

int is_complete(const struct binary_tree *tree)
{
    return is_cpl_rec(tree, size(tree), 0);
}

int is_degenerate(const struct binary_tree *tree)
{
    if (tree == NULL)
        return 1;
    if (tree->left && tree->right)
        return 0;
    if (is_degenerate(tree->left) == 0)
        return 0;
    if (is_degenerate(tree->right) == 0)
        return 0;
    return 1;
}

int is_full(const struct binary_tree *tree)
{
    if (tree == NULL || (tree->right == NULL && tree->left == NULL))
        return 1;
    if (tree->left != NULL && tree->right != NULL)
    {
        if (is_full(tree->left) == 0)
            return 0;
        if (is_full(tree->right) == 0)
            return 0;
        return 1;
    }
    return 0;
}

int get_max_bst(const struct binary_tree *tree)
{
    for (; tree->right != NULL; tree = tree->right)
        continue;
    return tree->data;
}

int get_min_bst(const struct binary_tree *tree)
{
    for (; tree->left != NULL; tree = tree->left)
        continue;
    return tree->data;
}

int is_bst(const struct binary_tree *tree)
{
    if (tree == NULL)
        return 1;
    int lm = get_max_bst(tree->left);
    int rm = get_min_bst(tree->right);
    if (lm > tree->data || rm <= tree->data)
        return 0;
    if (tree->left != NULL && tree->left->data >= tree->data)
        return 0;
    if (tree->right != NULL && tree->right->data < tree->data)
        return 0;
    if (is_bst(tree->left) == 0)
        return 0;
    if (is_bst(tree->right) == 0)
        return 0;
    return 1;
}
