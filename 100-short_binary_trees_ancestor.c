#include "binary_trees.h"

/**
 * binary_trees_ancestor - Locate the lowest shared ancestor of two nodes.
 * @first: A pointer to the first node to evaluate.
 * @second: A pointer to the second node to evaluate.
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if none exists.
 */
const binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
                                           const binary_tree_t *second)
{
	const binary_tree_t *parent_first, *parent_second;

	/* Check for NULL pointers */
	if (!first || !second)
		return (NULL);

	/* If both nodes are the same, return either */
	if (first == second)
		return (first);

	parent_first = first->parent;
	parent_second = second->parent;

	/* Check if either node is the parent of the other */
	if (first == parent_second || !parent_first ||
	    (!parent_first->parent && parent_second))
		return (binary_trees_ancestor(first, parent_second));
	else if (parent_first == second || !parent_second ||
	         (!parent_second->parent && parent_first))
		return (binary_trees_ancestor(parent_first, second));

	/* Recursive call to continue the search */
	return (binary_trees_ancestor(parent_first, parent_second));
}
