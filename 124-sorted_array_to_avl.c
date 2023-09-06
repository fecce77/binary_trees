#include "binary_trees.h"

/**
 * create_tree - Recursively constructs an AVL tree.
 * @node: Double pointer to the current node.
 * @array: Pointer to the array of sorted integers.
 * @size: Number of elements in the array.
 * @mode: Flag to indicate left or right subtree (1 for left, 2 for right).
 *
 * Return: None.
 */
void create_tree(avl_t **node, int *array, size_t size, int mode)
{
	size_t middle;

	if (size == 0)
		return;

	middle = size / 2;
	middle = (size % 2 == 0) ? middle - 1 : middle;

	if (mode == 1)
	{
		(*node)->left = binary_tree_node(*node, array[middle]);
		create_tree(&((*node)->left), array, middle, 1);
		create_tree(&((*node)->left), array + middle + 1, size - 1 - middle, 2);
	}
	else
	{
		(*node)->right = binary_tree_node(*node, array[middle]);
		create_tree(&((*node)->right), array, middle, 1);
		create_tree(&((*node)->right), array + middle + 1, size - 1 - middle, 2);
	}
}

/**
 * sorted_array_to_avl - Transforms a sorted array into an AVL tree.
 * @array: Pointer to the sorted array of integers.
 * @size: Number of elements in the array.
 *
 * Return: Pointer to the root node of the newly created AVL tree, or NULL if failed.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t middle;

	if (size == 0)
		return (NULL);

	middle = size / 2;
	middle = (size % 2 == 0) ? middle - 1 : middle;

	root = binary_tree_node(root, array[middle]);

	create_tree(&root, array, middle, 1);
	create_tree(&root, array + middle + 1, size - 1 - middle, 2);

	return (root);
}
