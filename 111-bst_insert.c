#include "binary_trees.h"

/**
 * bst_insert - Add a node containing a value to a Binary Search Tree.
 * @tree: Double pointer to the root node of the target BST.
 * @value: The integer to be placed in the new node.
 *
 * Return: Pointer to the newly created node or NULL if unsuccessful.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *curr = NULL, *new = NULL;

	/* Check for NULL tree */
	if (tree == NULL)
	{
		return (NULL);
	}

	/* Obtain current root node */
	curr = *tree;

	/* Insert at root if tree is empty */
	if (curr == NULL)
	{
		new = binary_tree_node(curr, value);
		if (new == NULL)
		{
			return (NULL);
		}
		*tree = new;
		return (new);
	}

	/* Navigate and insert into left subtree */
	if (value < curr->n)
	{
		if (curr->left != NULL)
		{
			return (bst_insert(&(curr->left), value));
		}
		new = binary_tree_node(curr, value);
		if (new == NULL)
		{
			return (NULL);
		}
		curr->left = new;
		return (new);
	}

	/* Navigate and insert into right subtree */
	if (value > curr->n)
	{
		if (curr->right != NULL)
		{
			return (bst_insert(&(curr->right), value));
		}
		new = binary_tree_node(curr, value);
		if (new == NULL)
		{
			return (NULL);
		}
		curr->right = new;
		return (new);
	}

	/* Return NULL if value exists */
	return (NULL);
}
