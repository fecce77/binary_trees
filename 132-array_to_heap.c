#include "binary_trees.h"

/**
 * array_to_heap - Constructs a Max Binary Heap from a given array.
 * @array: Pointer to the initial element of the input array.
 * @size: Total number of elements in the array.
 *
 * Return: Pointer to the root node of the newly created Max Binary Heap,
 *         or NULL if the operation fails.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root = NULL;
	size_t i;

	for (i = 0; i < size; i++)
	{
		heap_insert(&root, array[i]);
	}
	return (root);
}
