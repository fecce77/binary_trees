#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Description: If tree is NULL, the function returns 0.
 * Otherwise, it returns the height of the tree.
 *
 * Return: Height of the tree or 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_height = 0;
	size_t r_height = 0;

	if (tree == NULL)
	{
		return (0);
	}

	if (tree->left)
	{
		l_height = 1 + binary_tree_height(tree->left);
	}

	if (tree->right)
	{
		r_height = 1 + binary_tree_height(tree->right);
	}

	return ((l_height > r_height) ? l_height : r_height);
}
