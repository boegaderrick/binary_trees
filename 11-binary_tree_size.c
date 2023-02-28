#include "binary_trees.h"

/**
 * helper - recursive function to perform count
 * @tree: subject tree
 * @size: address to store number of nodes counted
 */
void helper(const binary_tree_t *tree, size_t *size)
{
	if (tree)
	{
		(*size)++;
		helper(tree->left, size);
		helper(tree->right, size);
	}
}

/**
 * binary_tree_size - computes the size of a binary tree
 * @tree: the binary to be computed
 *
 * Return: size of the tree or 0 if the tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	helper(tree, &size);
	return (size);
}
