#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts node as right-child of another node.
 * @parent: A pointer to the parent node of the node to insert.
 * @value: The value to put in the new node.
 * Return: Pointer to the new node, or NULL on failure or if parent is NULL.
 * Description: If parent already has a right-child, the new node must take its
 * place, and the old right-child must be set as the right-child of the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}
	parent->right = new_node;

	return (new_node);
}
