#include "binary_trees.h"

/**
 * binary_tree_postorder - postorder traversal of a binary tree
 * @tree: pointer to tree to be traversed
 * @func: pointer to function to be called at each node visit
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
