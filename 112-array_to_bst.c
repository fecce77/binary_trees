#include "binary_trees.h"

/**
 * array_to_bst - Constructs a binary search tree using an array's elements
 * @array: Address of the array's first element to transform
 * @size: Total count of elements in array
 *
 * Return: Pointer to root node of constructed BST, or NULL if operation fails
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i, j;

	/* Check if input array is NULL */
	if (array == NULL)
		return (NULL);

	/* Loop through the array */
	for (i = 0; i < size; i++)
	{
		/* Search for duplicates before current index */
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}
		/* Insert unique elements into BST */
		if (j == i)
		{
			if (bst_insert(&tree, array[i]) == NULL)
				return (NULL);
		}
	}
	return (tree);
}
