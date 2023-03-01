#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds closest mutual ancestor of two nodes
 * @first: pointer to first node
 * @second: pointer to secong node
 *
 * Return: pointer to ancestor or NULL if none exists
 */
binary_tree_t *binary_trees_ancestor(
		const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *pf = (binary_tree_t *)first;
	binary_tree_t *ps = (binary_tree_t *)second, *a[20];
	int i = 0;

	if (first == NULL || second == NULL)
		return (NULL);

	while (pf)
	{
		a[i] = pf;
		pf = pf->parent;
		i++;
	}
	a[i] = NULL;
	i = 0;
	while (ps)
	{
		for (i = 0; a[i] != NULL; i++)
		{
			if (ps->n == a[i]->n)
				return (a[i]);
		}
		ps = ps->parent;
	}
	return (NULL);
}
