#include "binary_trees.h"
#include "limits.h"

int is_avl_helper(const binary_tree_t *tree, int *height, int lo, int hi);

/**
 * is_avl_helper - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @height: A pointer to an int where the height will be stored.
 * @lo: The value of the smallest node visited thus far.
 * @hi: The value of the largest node visited this far.
 *
 * Return: If the tree is a valid AVL tree, return 1, otherwise, return 0.
 */
int is_avl_helper(const binary_tree_t *tree, int *height, int lo, int hi)
{
	int lh = 0, rh = 0, diff;

	if (tree == NULL)
	{
		*height = 0;
		return (1);
	}

	if (tree->n < lo || tree->n > hi)
		return (0);

	if (!is_avl_helper(tree->left, &lh, lo, tree->n - 1) ||
		!is_avl_helper(tree->right, &rh, tree->n + 1, hi))
		return (0);

	diff = lh - rh;
	if (diff > 1 || diff < -1)
		return (0);

	*height = (lh > rh ? lh : rh) + 1;
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height = 0;

	if (tree == NULL)
		return (0);

	return (is_avl_helper(tree, &height, INT_MIN, INT_MAX));
}
