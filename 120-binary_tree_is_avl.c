#include "binary_trees.h"

void helper(binary_tree_t *root, binary_tree_t *tree, bool *bst);
size_t height(const binary_tree_t *tree, bool *valid);
int is_bst(const binary_tree_t *tree);

/**
 * binary_tree_is_avl - checks if a binary tree is valid avl
 * @tree: pointer to subject tree
 *
 * Return: 1 if true, 0 if otherwise or operation failed
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int x;
	bool valid = true;

	if (tree == NULL)
		return (0);

	x = is_bst(tree);
	height(tree, &valid);

	if (x == 1 && valid)
		return (1);
	return (0);
}

/**
 * height - calculates height of a binary tree
 * @tree: subject tree
 * @valid: pointer to boolean that signifies validity or otherwise
 *
 * Return: height of the tree or 0 if if tree is NULL
 */
size_t height(const binary_tree_t *tree, bool *valid)
{
	int right = 0, left = 0;

	if (!valid || tree == NULL || (!tree->left && !tree->right))
	/*if (tree == NULL)*/
		return (0);

	left = height(tree->left, valid);
	right = height(tree->right, valid);
	if (abs(left - right))
		(*valid) = false;

	return (1 + (left > right ? left : right));
}

/**
 * is_bst - checks if a tree is a bst
 * @tree: tree to be checked
 *
 * Return: 1 if tree is a bst, 0 otherwise
 */
int is_bst(const binary_tree_t *tree)
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
