#include "binary_trees.h"

/**
 * bal - Measures balance factor of an AVL tree and rotates nodes as necessary.
 * @tree: Pointer to the root node of the tree.
 */
void bal(avl_t **tree)
{
	int bval;

	if (!tree || !*tree)
		return;
	if (!(*tree)->left && !(*tree)->right)
		return;
	bal(&(*tree)->left);
	bal(&(*tree)->right);
	bval = binary_tree_balance((const binary_tree_t *)*tree);
	if (bval > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bval < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * successor - Finds the in-order successor of a node.
 * @node: Pointer to the node.
 * Return: Value of the in-order successor.
 */
int successor(bst_t *node)
{
	int left;

	if (!node)
		return (0);
	left = successor(node->left);
	if (left == 0)
		return (node->n);
	return (left);
}

/**
 * remove_type - Removes a node based on its number of children.
 * @root: Pointer to the node to remove.
 * Return: 0 if node has no children, otherwise returns the successor value.
 */
int remove_type(bst_t *root)
{
	int new_value = 0;
	bst_t **parent_link;

	if (!root->left && !root->right)
	{
		parent_link = (root->parent->right == root) ? &root->parent->right : &root->parent->left;
		*parent_link = NULL;
		free(root);
		return (0);
	}
	else if (!root->left || !root->right)
	{
		bst_t *child = root->left ? root->left : root->right;
		parent_link = (root->parent->right == root) ? &root->parent->right : &root->parent->left;
		*parent_link = child;
		child->parent = root->parent;
		free(root);
		return (0);
	}
	new_value = successor(root->right);
	root->n = new_value;
	return (new_value);
}

/**
 * bst_remove - Removes a node from a BST.
 * @root: Pointer to the root node of the tree.
 * @value: Value of the node to remove.
 * Return: Pointer to the root node after removal.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type;

	if (!root)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else
	{
		type = remove_type(root);
		if (type)
			bst_remove(root->right, type);
	}
	return (root);
}

/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: Pointer to the root node of the tree.
 * @value: Value of the node to remove.
 * Return: Pointer to the root node after removal.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *)bst_remove((bst_t *)root, value);

	if (!root_a)
		return (NULL);
	bal(&root_a);
	return (root_a);
}
