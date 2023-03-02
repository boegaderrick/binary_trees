#include "binary_trees.h"

/**
 * binary_tree_levelorder - prints binary tree in levelorder
 * @tree: pointer to tree to be printed
 * @func: pointer to function to handle printing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *q[20] = {NULL};
	int f = 0, l = 0;

	if (tree == NULL || func == NULL)
		return;

	q[0] = (binary_tree_t *)tree;
	while (q[f] != NULL)
	{
		func(q[f]->n);
		q[++l] = q[f]->left;
		q[++l] = q[f++]->right;
	}
}
