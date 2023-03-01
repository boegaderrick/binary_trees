#include "binary_trees.h"

void helper(const binary_tree_t *tree, size_t *depth);

/**
 * binary_tree_depth - calculates depth of a node
 * @tree: pointer to subject node
 *
 * Return: depth of node or zero if node is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);

	helper(tree, &depth);
	return (depth);
}

/**
 * helper - recursive function to traverse tree and count edges
 * @tree: subject tree
 * @depth: memory address to store count
 */
void helper(const binary_tree_t *tree, size_t *depth)
{
	if (tree->parent)
	{
		(*depth)++;
		helper(tree->parent, depth);
	}
}
