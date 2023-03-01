#include "binary_trees.h"

size_t height(const binary_tree_t *tree, bool *perfect);

/**
 * binary_tree_is_perfect - checks if binary tree is perfect
 * @tree: subject tree
 *
 * Return: 1 if tree is balanced, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	bool perfect = true;

	if (tree == NULL)
		return (0);

	height(tree, &perfect);
	return (perfect ? 1 : 0);
}

/**
 * height - calculates height of a binary tree
 * @tree: subject tree
 * @perfect: boolean pointer to record whether or not tree is perfect
 *
 * Return: height of the tree or 0 if if tree is NULL
 */
size_t height(const binary_tree_t *tree, bool *perfect)
{
	size_t right = 0, left = 0;

	/*if (tree == NULL || (!tree->left && !tree->right))*/
	if (tree == NULL)
		return (0);

	left = height(tree->left, perfect);
	right = height(tree->right, perfect);
	if (left != right)
		(*perfect) = false;

	return (1 + (left > right ? left : right));
}
