#include "binary_trees.h"

/**
 * binary_trees_ancestor - Identify the nearest shared ancestor of two nodes.
 * @first: A pointer to the initial node.
 * @second: A pointer to the secondary node.
 *
 * Return: NULL if no shared ancestors, otherwise the closest common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *mom = NULL;
	binary_tree_t *pop = NULL;

	/* Check for NULL pointers */
	if (!first || !second)
		return (NULL);

	/* If both nodes are the same, return either */
	if (first == second)
		return ((binary_tree_t *)first);

	mom = first->parent;
	pop = second->parent;

	/* Check various conditions to find the common ancestor */
	if (first == pop || !mom || (!mom->parent && pop))
		return (binary_trees_ancestor(first, pop));
	else if (mom == second || !pop || (!pop->parent && mom))
		return (binary_trees_ancestor(mom, second));

	return (binary_trees_ancestor(mom, pop));
}
