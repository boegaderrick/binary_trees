#include "binary_trees.h"

/**
 * array_to_bst - builds a binary search tree from an array
 * @array: pointer to array containing values to be stored in bst
 * @size: number of items in array
 *
 * Return: pointer to new bst, NULL incase of failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i;

	if (size < 1 || array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		bst_insert(&root, array[i]);
	return (root);
}
