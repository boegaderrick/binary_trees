#include "binary_trees.h"

void helper(const binary_tree_t *tree, size_t *nodes);

/**
 * binary_tree_nodes - counts number of leaves in a binary tree
 * @tree: pointer to subject tree
 *
 * Return: number of leaves or 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	helper(tree, &nodes);
	return (nodes);
}

/**
 * helper - recursive function to perform count
 * @tree: subject tree
 * @nodes: address to store number of counted nodes
 */
void helper(const binary_tree_t *tree, size_t *nodes)
{
	if (tree)
	{
		if (tree->left != NULL || tree->right != NULL)
			(*nodes)++;
		helper(tree->left, nodes);
		helper(tree->right, nodes);
	}
}

