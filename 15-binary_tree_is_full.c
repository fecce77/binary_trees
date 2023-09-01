#include "binary_trees.h"

/**
 * is_full_recursive - Recursively determines if a binary tree is full.
 * @tree: Pointer to the root node of the tree under examination.
 *
 * Return: 0 if the tree is not full, 1 if it is.
 */
int is_full_recursive(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if ((tree->left == NULL && tree->right != NULL) ||
		(tree->left != NULL && tree->right == NULL))
		return (0);

	if (is_full_recursive(tree->left) == 0 ||
		is_full_recursive(tree->right) == 0)
		return (0);

	return (1);
}

/**
 * binary_tree_is_full - Evaluates if a binary tree is full.
 * @tree: Pointer to the root node of the tree to evaluate.
 *
 * Return: 0 if the tree is NULL or not full, 1 otherwise.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_full_recursive(tree));
}
