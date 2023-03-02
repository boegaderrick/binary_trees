#include "binary_trees.h"

void search(const bst_t *tree, int value, bst_t **node);

/**
 * bst_search - searches for node in binary tree
 * @tree: tree to be searched
 * @value: value contained in node being searched for
 *
 * Return: pointer to node, NULL if it doesn't exist
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *node = NULL;

	search(tree, value, &node);
	return (node);
}

/**
 * search - recursive function to perform the search
 * @tree: pointer to bst to be searched
 * @value: value contained in node to be searched for
 * @node: pointer to store node if found
 */
void search(const bst_t *tree, int value, bst_t **node)
{
	if (tree && !node)
	{
		if (value == tree->n)
		{
			*node = (bst_t *)tree;
			return;
		}

		if (value < tree->n)
			search(tree->left, value, node);
		if (value > tree->n)
			search(tree->right, value, node);
	}
}
