#include "binary_trees.h"

/**
 * depth - Calculate the node's depth in a binary tree.
 * @tree: Pointer to the node whose depth is to be calculated.
 *
 * Return: The depth of the node. If tree is NULL, return 0.
 */
size_t depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return ((tree->parent != NULL) ? 1 + depth(tree->parent) : 0);
}

/**
 * binary_trees_ancestor - Identify the lowest common ancestor of two nodes.
 * @first: Pointer to the first node in question.
 * @second: Pointer to the second node in question.
 *
 * Return: Pointer to the lowest common ancestor, or NULL if none found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	const binary_tree_t *second)
{
	size_t first_depth, second_depth;

	if (first == NULL || second == NULL)
		return (NULL);
	if (first == second || first->parent == second || second->parent == first)
		return ((binary_tree_t *)first);
	if (first->parent == second->parent)
		return ((binary_tree_t *)first->parent);

	first_depth = depth(first);
	second_depth = depth(second);

	while (first_depth > 0)
	{
		first = first->parent;
		first_depth--;
	}
	while (second_depth > 0)
	{
		second = second->parent;
		second_depth--;
	}

	if (first == second || first->parent == second || second->parent == first)
		return ((binary_tree_t *)first);
	if (first->parent == second->parent)
		return ((binary_tree_t *)first->parent);

	return (NULL);
}
