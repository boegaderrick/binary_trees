#include "binary_trees.h"

/**
 * binary_tree_height - calculates height of a binary tree
 * @tree: subject tree
 *
 * Return: height of the tree or 0 if if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t right = 0, left = 0;

	if (tree == NULL || (!tree->left && !tree->right))
		return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	return (1 + (right > left ? right : left));
}
