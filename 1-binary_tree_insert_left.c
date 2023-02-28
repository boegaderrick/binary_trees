#include "binary_trees.h"

/**
 * binary_tree_insert_left - creates node and inserts it to binary tree
 * @parent: root node of binary tree
 * @value: value to be stored in new node
 *
 * Return: pointer to new node or NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);
	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);
	new->n = value;
	new->parent = parent;
	new->left = parent->left;
	if (new->left != NULL)
		new->left->parent = new;
	new->right = NULL;
	parent->left = new;

	return (new);
}
