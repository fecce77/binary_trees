#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"

/**
 * check_max - Validate if each node in the tree is greater than its children.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree satisfies the max-heap property, 0 otherwise.
 */
int check_max(const binary_tree_t *tree)
{
	int left_check = 1, right_check = 1;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
	{
		if (tree->n <= tree->left->n)
			return (0);
		left_check = check_max(tree->left);
	}
	if (tree->right)
	{
		if (tree->n <= tree->right->n)
			return (0);
		right_check = check_max(tree->right);
	}
	return (left_check && right_check);
}

/**
 * binary_tree_is_heap - Determine if a binary tree is a max-heap.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a max-heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int is_complete;

	if (!tree)
		return (0);

	is_complete = binary_tree_is_complete(tree);
	if (!is_complete)
		return (0);

	return (check_max(tree));
}
