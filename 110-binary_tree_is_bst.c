#include "binary_trees.h"

void helper(binary_tree_t *root, binary_tree_t *tree, bool *bst);

/**
 * binary_tree_is_bst - checks if a tree is a bst
 * @tree: tree to be checked
 *
 * Return: 1 if tree is a bst, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	bool bst = true;
	binary_tree_t *root = (binary_tree_t *)tree;

	if (tree == NULL)
		return (0);

	helper(root, (binary_tree_t *)tree, &bst);
	return (bst ? 1 : 0);
}

/**
 * helper - recursive function to traverse tree and check if it is a bst
 * @root: pointer to greatest ancestor of tree
 * @tree: pointer to tree to be checked
 * @bst: pointer to boolean value to be modified if tree is not a bst
 */
void helper(binary_tree_t *root, binary_tree_t *tree, bool *bst)
{
	if (root->parent != NULL)
	{
		while (root->parent)
			root = root->parent;
	}
	if (tree && tree->left && tree->left->n >= tree->n)
		(*bst) = false;
	if (tree && tree->right && tree->right->n <= tree->n)
		(*bst) = false;
	if (tree && tree->parent)
	{
		if (tree->parent->n > root->n && tree->n <= root->n)
			(*bst) = false;
		if (tree->parent->n < root->n && tree->n >= root->n)
			(*bst) = false;
	}
	if (bst && tree)
	{
		helper(root, tree->left, bst);
		helper(root, tree->right, bst);
	}
}
