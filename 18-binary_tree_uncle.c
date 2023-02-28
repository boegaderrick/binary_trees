#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node in a tree
 * @node: pointer to node whose uncle is sought
 *
 * Return: pointer to uncle if it exists, otherwise NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL)
		return (NULL);

	node = node->parent;
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
