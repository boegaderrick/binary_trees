#include "binary_trees.h"

/**
 * binary_tree_rotate_left - left rotates binary tree
 * @tree: pointer to root node of tree to be rotated
 *
 * Return: pointer to new root or NULL if tree is NULL
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	if (tree == NULL)
		return (NULL);

	if (tree->parent)
	{
		if (tree->parent->left == tree)
			tree->parent->left = tree->right;
		else
			tree->parent->right = tree->right;
	}
	tree->right->parent = tree->parent;
	tree->parent = tree->right;
	tree->right = tree->parent->left;
	if (tree->right)
		tree->right->parent = tree;
	tree->parent->left = tree;

	return (tree->parent);
}
