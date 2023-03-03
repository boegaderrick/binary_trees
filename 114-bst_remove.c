#include "binary_trees.h"

void r_search(const bst_t *tree, int value, bst_t **node);
bst_t *bst_t_search(const bst_t *tree, int value);

/**
 * bst_remove - deletes node from a bst
 * @root: pointer to bst
 * @value: value stored in node to be deleted
 *
 * Return: pointer to new root, NULL if operation failed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node = bst_t_search(root, value), *new;

	if (!root || !node)
		return (NULL);

	if (!node->right && !node->left)
	{
		if (node->parent->left == node)
			node->parent->left = NULL;
		else
			node->parent->right = NULL;
		node->parent = NULL;
		free(node);
		return (root);
	}

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



/**
 * bst_t_search - searches for node in binary tree
 * @tree: tree to be searched
 * @value: value contained in node being searched for
 *
 * Return: pointer to node, NULL if it doesn't exist
 */
bst_t *bst_t_search(const bst_t *tree, int value)
{
	bst_t *node = NULL;

	r_search(tree, value, &node);
	return (node);
}

/**
 * r_search - recursive function to perform the search
 * @tree: pointer to bst to be searched
 * @value: value contained in node to be searched for
 * @node: pointer to store node if found
 */
void r_search(const bst_t *tree, int value, bst_t **node)
{
	if (tree && !*node)
	{
		if (value == tree->n)
		{
			*node = (bst_t *)tree;
			return;
		}

		if (value < tree->n)
			r_search(tree->left, value, node);
		if (value > tree->n)
			r_search(tree->right, value, node);
	}
}
