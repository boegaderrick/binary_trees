#include "binary_trees.h"

void helper(bst_t *tree, bst_t *new, bool *ignore, bool *done);
bst_t *b_search(const bst_t *tree, int value);
void search(const bst_t *tree, int value, bst_t **node);


/**
 * bst_insert - inserts a node into a binary search tree
 * @tree: double pointer to tree
 * @value: value to be stored in new node
 *
 * Return: pointer to new node, NULL if op failed or duplicate is present
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new;
	bool ignore = false, done = false;

	if (b_search(*tree, value))
		return (NULL);

	new = binary_tree_node(NULL, value);
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



/**
 * b_search - searches for node in binary tree
 * @tree: tree to be searched
 * @value: value contained in node being searched for
 *
 * Return: pointer to node, NULL if it doesn't exist
 */
bst_t *b_search(const bst_t *tree, int value)
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
	if (tree && !*node)
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
