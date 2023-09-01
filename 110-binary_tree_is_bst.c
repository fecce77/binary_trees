#include "binary_trees.h"
#include "limits.h"

/**
 * is_bst_helper - Validates if a subtree is a binary search tree.
 * @tree: Pointer to the root node of the subtree to validate.
 * @lo: Minimum allowable value for nodes in this subtree.
 * @hi: Maximum allowable value for nodes in this subtree.
 *
 * Return: 1 if the subtree is a valid BST, 0 otherwise.
 */
int is_bst_helper(const binary_tree_t *tree, int lo, int hi)
{
	if (tree == NULL)
		return (1);
	if (tree->n < lo || tree->n > hi)
		return (0);
	return (is_bst_helper(tree->left, lo, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, hi));
}

/**
 * binary_tree_is_bst - Determines if a binary tree is a binary search tree.
 * @tree: Pointer to the root node of the tree to validate.
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
