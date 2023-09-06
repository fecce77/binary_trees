#include "binary_trees.h"

/**
 * bst_search - Find a specified value within a binary search tree.
 * @tree: Pointer to the root node of the BST to be searched.
 * @value: The numerical value to locate within the BST.
 *
 * Return: Pointer to the node containing the target value.
 * If tree is NULL or value is not present, return NULL.
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	/* Check for an empty tree or end of a branch */
	if (tree == NULL)
	{
		return (NULL);
	}

	/* If the current node's value matches, return its pointer */
	if (tree->n == value)
	{
		return ((bst_t *)tree);
	}

	/* If the target value is smaller, search the left subtree */
	if (tree->n > value)
	{
		return (bst_search(tree->left, value));
	}

	/* Otherwise, search the right subtree */
	return (bst_search(tree->right, value));
}
