#include "binary_trees.h"

/**
 * binary_tree_inorder - inorder traversal of a binary tree
 * @tree: pointer to tree to be traversed
 * @func: pointer to function to be called at each node visit
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
