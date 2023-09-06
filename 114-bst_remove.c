#include "binary_trees.h"

/**
 * inorder_successor - Returns the inorder successor of a node in a BST.
 * @root: A pointer to the root node of the BST.
 *
 * Return: The inorder successor node.
 */
bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_delete - Deletes a node in a BST.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the node to delete.
 *
 * Return: The new root of the tree after deletion.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;
	bst_t *newRoot = root;

	if (node->left == NULL)
	{
		if (parent && parent->left == node)
			parent->left = node->right;
		else if (parent)
			parent->right = node->right;
		else
			newRoot = node->right;

		if (node->right)
			node->right->parent = parent;
		free(node);
		return (newRoot);
	}
	if (node->right == NULL)
	{
		if (parent && parent->left == node)
			parent->left = node->left;
		else if (parent)
			parent->right = node->left;
		else
			newRoot = node->left;

		if (node->left)
			node->left->parent = parent;
		free(node);
		return (newRoot);
	}
	successor = inorder_successor(node->right);
	node->n = successor->n;
	return (bst_delete(newRoot, successor));
}

/**
 * bst_remove_recursive - Removes a node recursively in a BST.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the current node.
 * @value: The value to be removed.
 *
 * Return: The new root of the tree after deletion.
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (!node)
		return (NULL);

	if (node->n == value)
		return (bst_delete(root, node));

	if (node->n > value)
		return (bst_remove_recursive(root, node->left, value));

	return (bst_remove_recursive(root, node->right, value));
}

/**
 * bst_remove - Removes a node in a BST.
 * @root: A pointer to the root node of the BST.
 * @value: The value to be removed.
 *
 * Return: The new root of the tree after deletion.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}
