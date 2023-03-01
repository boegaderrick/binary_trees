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
	binary_tree_t *pf = first->parent, *ps = second->parent;

	/*if (first == NULL || second == NULL)
		return (NULL);*/

	if (pf->n == second->n)
		return (pf);
	if (ps->n == first->n)
		return (ps);

	while (pf)
	{
		ps = second->parent;
		while (ps)
		{
			if (ps->n == pf->n)
				return (ps);
			ps = ps->parent;
		}
		pf = pf->parent;
	}
	return (NULL);
}
