#include "binary_trees.h"

int helper(const binary_tree_t *tree, size_t *right, size_t *left);

/**
 * binary_tree_height - calculates height of a binary tree
 * @tree: subject tree
 *
 * Return: heght of the tree or 0 if if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t right = 0, left = 0;
	int ret;

	if (tree == NULL)
		return (0);

	ret = helper(tree, &right, &left);
	return (ret + (right > left ? right : left));
}

/**
 * helper - recursive function to aid in traversal of tree and count of edges
 * @tree: pointer to subject tree
 * @right: pointer to right child of tree
 * @left: pointer to left child of tree
 *
 * Return: number of edges
 */
int helper(const binary_tree_t *tree, size_t *right, size_t *left)
{
	int i = 0, j = 0;

	if (tree)
	{
		if (tree->left)
		{
			i += 1;
			(*left) += helper(tree->left, right, left);
		}
		if (tree->right)
		{
			j += 1;
			(*right) += helper(tree->right, right, left);
		}
	}
	return (i > j ? i : j);
}
