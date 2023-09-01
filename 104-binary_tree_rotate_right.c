#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right rotation on a binary tree.
 * @tree: A pointer to the root node of the tree to be rotated.
 *
 * Return: A pointer to the new root node after the rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot, *tmp;

	/* Check if tree is NULL or left child is NULL, no rotation needed */
	if (tree == NULL || tree->left == NULL)
		return (NULL);

	/* Store the left child as pivot and its right child as tmp */
	pivot = tree->left;
	tmp = pivot->right;

	/* Perform the right rotation */
	pivot->right = tree;
	tree->left = tmp;

	/* Update parent pointers if tmp is not NULL */
	if (tmp != NULL)
		tmp->parent = tree;

	tmp = tree->parent;
	tree->parent = pivot;
	pivot->parent = tmp;

	/* Update parent's child pointer to pivot */
	if (tmp != NULL)
	{
		if (tmp->left == tree)
			tmp->left = pivot;
		else
			tmp->right = pivot;
	}

	/* Return the new root (pivot) of the rotated tree */
	return (pivot);
}
