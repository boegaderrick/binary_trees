#include "binary_trees.h"

void helper(const binary_tree_t *tree, int *x);

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: tree to be checked
 *
 * Return: 1 if binary tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int x = 1;

	if (tree == NULL)
		return (0);

	helper(tree, &x);
	return (x);
}

/**
 * helper - recursively checks if nodes have 0 or 2 children
 * @tree: pointer to tree to be traversed
 * @x: pointer to address storing value to represent status of tree
 */
void helper(const binary_tree_t *tree, int *x)
{
	if (tree && *x == 1)
	{
		if ((tree->left && !tree->right) || (!tree->left && tree->right))
			(*x) = 0;
		else
		{
			helper(tree->left, x);
			helper(tree->right, x);
		}
	}
}
