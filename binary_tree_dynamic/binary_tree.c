#include "binary_tree.h"

#include <stdio.h>
#include <stdlib.h>

int size(const struct binary_tree *tree)
{
    if (tree == NULL)
        return 0;
    return 1 + size(tree->left) + size(tree->right);
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(const struct binary_tree *tree)
{
    if (tree == NULL)
        return 0;
    return 1 + max(height(tree->left), height(tree->right));
}

void dfs_print_prefix(const struct binary_tree *tree)
{
    if (tree == NULL)
        return;
    printf("%d ", tree->data);
    dfs_print_prefix(tree->left);
    dfs_print_prefix(tree->right);
}

void dfs_print_infix(const struct binary_tree *tree)
{
    if (tree == NULL)
        return;
    dfs_print_prefix(tree->left);
    printf("%d ", tree->data);
    dfs_print_prefix(tree->right);
}
void dfs_print_postfix(const struct binary_tree *tree)
{
    if (tree == NULL)
        return;
    dfs_print_prefix(tree->left);
    dfs_print_prefix(tree->right);
    printf("%d ", tree->data);
}

int is_perfect(const struct binary_tree *tree)
{
    if (tree == NULL)
        return 1;
    if (tree->right == NULL || tree->right == NULL)
        return 0;
    if (is_perfect(tree->left) == 0)
        return 0;
    if (is_perfect(tree->right) == 0)
        return 0;
    return 1;
}

static char is_cpl_rec(const struct binary_tree *tree, size_t size, size_t i)
{
    if (tree == NULL)
        return 1;
    if (i >= size)
        return 0;
    if (is_cpl_rec(tree, size, 2 * i + 1) == 0)
        return 0;
    if (is_cpl_rec(tree, size, 2 * i + 2) == 0)
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
    if (tree == NULL)
        return 1;
    if (tree->left && tree->right)
    {
        if (is_full(tree->left) == 0)
            return 0;
        if (is_full(tree->right) == 0)
            return 0;
        return 1;
    }
    return 0;
}

int is_bst(const struct binary_tree *tree)
{
    if (tree == NULL)
        return 1;
    if (tree->left != NULL && tree->left->data > tree->data)
    {
        return 0;
    }
    if (tree->right != NULL && tree->right->data <= tree->data)
    {
        return 0;
    }
    return is_bst(tree->left) & is_bst(tree->right);
}
