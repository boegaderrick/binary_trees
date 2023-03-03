#include "binary_trees.h"

void helper(bst_t *tree, bst_t *new, bool *ignore, bool *done);

/**
 * bst_insert - inserts a node into a binary search tree
 * @tree: double pointer to tree
 * @value: value to be stored in new node
 *
 * Return: pointer to new node, NULL if op failed or duplicate is present
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new = binary_tree_node(NULL, value);
	bool ignore = false, done = false;

	if (new == NULL)
		return (NULL);

	if (!tree || (tree && *tree == NULL))
	{
		if (!tree)
			tree = &new;
		if (!*tree)
			*tree = new;
		return (new);
	}
	helper(*tree, new, &ignore, &done);
	return (ignore ? NULL : new);
}

/**
 * helper - helper function to aid in the insertion
 * @tree: pointer to tree
 * @new: pointer to new node
 * @ignore: pointer to boolean to be modified incase a duplicate is present
 * @done: pointer to boolean that signals when to stop
 */
void helper(bst_t *tree, bst_t *new, bool *ignore, bool *done)
{
	if (new->n == tree->n)
	{
		free(new);
		(*ignore) = true;
	}

	if (*done || *ignore)
		return;

	if (new->n > tree->n)
	{
		if (tree->right)
			helper(tree->right, new, ignore, done);
		else
		{
			tree->right = new;
			new->parent = tree;
			(*done) = true;
		}
	}
	if (new->n < tree->n)
	{
		if (tree->left)
			helper(tree->left, new, ignore, done);
		else
		{
			tree->left = new;
			new->parent = tree;
			(*done) = true;
		}
	}
}
