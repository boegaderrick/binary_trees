#include "binary_trees.h"

/**
 * binary_tree_rotate_right - right rotates binary tree
 * @tree: pointer to root node of tree to be rotated
 *
 * Return: pointer to new root or NULL if tree is NULL
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	if (tree == NULL)
		return (NULL);

	if (tree->parent)
	{
		if (tree->parent->left == tree)
			tree->parent->left = tree->left;
		else
			tree->parent->right = tree->left;
	}
	tree->left->parent = tree->parent;
	tree->parent = tree->left;
	tree->left = tree->parent->right;
	tree->parent->right = tree;

	return (tree->parent);
}
