#include "binary_trees.h"

/**
 * is_leaf - Determines if a given node is a leaf node in a binary tree.
 * @node: Pointer to the node under examination.
 * Return: 1 if it's a leaf node, 0 otherwise.
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * depth - Computes the depth level of a specific node in a binary tree.
 * @tree: Pointer to the node whose depth is to be calculated.
 * Return: Depth level of the node.
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * get_leaf - Finds a leaf node in a binary tree.
 * @tree: Pointer to the root node of the tree where the search starts.
 * Return: Pointer to the first leaf node encountered.
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree))
		return (tree);
	if (tree->left)
		return (get_leaf(tree->left));
	return (get_leaf(tree->right));
}

/**
 * is_perfect_recursive - Recursively verifies if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree under examination.
 * @leaf_depth: Depth level of a leaf node in the binary tree.
 * @level: Current level of the node being examined.
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int is_perfect_recursive(const binary_tree_t *tree,
						 size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth);
	if (!tree->left || !tree->right)
		return (0);
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
			is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - Validates if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to validate.
 * Return: 0 if the tree is either NULL or not perfect, 1 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}
