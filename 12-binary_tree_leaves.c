#include "binary_trees.h"

void helper(const binary_tree_t *tree, size_t *leaves);

/**
 * binary_tree_leaves - counts number of leaves in a binary tree
 * @tree: pointer to subject tree
 *
 * Return: number of leaves or 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	helper(tree, &leaves);
	return (leaves);
}

/**
 * helper - recursive function to perform count
 * @tree: subject tree
 * @leaves: address to store number of counted nodes
 */
void helper(const binary_tree_t *tree, size_t *leaves)
{
	if (tree)
	{
		if (tree->left == NULL && tree->right == NULL)
			(*leaves)++;
		helper(tree->left, leaves);
		helper(tree->right, leaves);
	}
}

