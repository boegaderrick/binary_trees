#include "binary_trees.h"

/**
 * bst_remove - deletes node from a bst
 * @root: pointer to bst
 * @value: value stored in node to be deleted
 *
 * Return: pointer to new root, NULL if operation failed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node, *new;

	node = bst_search(root, value), *new;

	if (!root || !node)
		return (NULL);

	if (node->right && node->left)
	{
		new = node->right;
		while (new->left)
			new = new->left;

		if (new->parent != node)
		{
			new->parent->left = new->right;
			if (new->right)
				new->right->parent = new->parent;
			new->right = node->right;
			if (node->right)
				new->right->parent = new;
		}
		new->left = node->left;
		if (new->left)
			new->left->parent = new;
	}
	else if (node->right && !node->left)
		new = node->right;
	else if (!node->right && node->left)
		new = node->left;
	new->parent = node->parent;
	if (new->parent)
	{
		if (new->parent->left == node)
			new->parent->left = new;
		else
			new->parent->right = new;
	}
	else
		root = new;
	free(node);
	return (root);
}
