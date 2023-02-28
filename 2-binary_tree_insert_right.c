#include "binary_trees.h"

/**
 * binary_tree_insert_right - creates node and inserts it to binary tree
 * @parent: root node of binary tree
 * @value: value to be stored in new node
 *
 * Return: pointer to new node or NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);
	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);
	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = parent->right;
	if (new->right != NULL)
		new->right->parent = new;
	parent->right = new;

	return (new);
}
