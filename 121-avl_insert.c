#include "binary_trees.h"

/**
 * height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, return 0, else return height.
 */
size_t height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	size_t l_height = 1 + height(tree->left);
	size_t r_height = 1 + height(tree->right);

	return ((l_height > r_height) ? l_height : r_height);
}

/**
 * balance - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: If tree is NULL, return 0, else return balance factor.
 */
int balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (height(tree->left) - height(tree->right));
}

/**
 * avl_insert_recursive - Inserts a value into an AVL tree recursively.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @parent: The parent node of the current working node.
 * @new: A double pointer to store the new node.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the new root after insertion, or NULL on failure.
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
							avl_t **new, int value)
{
	int b_factor;

	if (!*tree)
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		if (!((*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, new, value)))
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		if (!((*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, new, value)))
			return (NULL);
	}
	else
		return (*tree);

	b_factor = balance(*tree);
	if (b_factor > 1 && (*tree)->left->n > value)
		return (*tree = binary_tree_rotate_right(*tree));
	if (b_factor < -1 && (*tree)->right->n < value)
		return (*tree = binary_tree_rotate_left(*tree));
	if (b_factor > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		return (*tree = binary_tree_rotate_right(*tree));
	}
	if (b_factor < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		return (*tree = binary_tree_rotate_left(*tree));
	}
	return (*tree);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (!tree)
		return (NULL);

	if (!*tree)
		return (*tree = binary_tree_node(NULL, value));

	avl_insert_recursive(tree, *tree, &new_node, value);
	return (new_node);
}
