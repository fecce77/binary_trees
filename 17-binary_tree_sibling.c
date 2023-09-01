#include "binary_trees.h"

/**
 * binary_tree_sibling - Retrieve the sibling node of a given node.
 * @node: Pointer to the target node.
 *
 * Return: Pointer to the sibling node if it exists, NULL otherwise.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	/* Check if node or its parent is NULL */
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/* If node is the left child, return the right child */
	if (node->parent->left == node)
		return (node->parent->right);

	/* If node is the right child, return the left child */
	return (node->parent->left);
}
