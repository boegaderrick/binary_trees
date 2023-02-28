#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node in a tree
 * @node: pointer to node whose sibling is sought
 *
 * Return: pointer to sibling if it exists, otherwise NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node && node->parent)
	{
		if ((node->parent->left) == node)
			return (node->parent->right);
		else
			return (node->parent->left);
	}
	else
		return (NULL);
}
