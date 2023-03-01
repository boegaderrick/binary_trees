#include "binary_trees.h"
#include <stdio.h>

size_t height(const binary_tree_t *tree);

/**
 * binary_tree_balance - checks if binary tree is balanced
 * @tree: subject tree
 *
 * Return: 1 if tree is balanced, 0 otherwise
 */
size_t binary_tree_balance(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	left = height(tree->left);
	right = height(tree->right);
	return (left - right);
}

/**
 * height - calculates height of a binary tree
 * @tree: subject tree
 *
 * Return: heght of the tree or 0 if if tree is NULL
 */
size_t height(const binary_tree_t *tree)
{
	size_t right = 0, left = 0;

	/*if (tree == NULL || (!tree->left && !tree->right))*/
	if (tree == NULL)
		return (0);

	left = height(tree->left);
	right = height(tree->right);

	return (1 + (left > right ? left : right));
}
