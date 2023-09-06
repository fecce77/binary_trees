#include "binary_trees.h"

/**
 * array_to_avl - Convert an array into an AVL tree.
 * @array: Pointer to the array's first element.
 * @size: Number of elements in the array.
 *
 * Return: Pointer to the root of the generated AVL tree, or NULL if failed.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t i, j;

	/* Return NULL if the input array is NULL */
	if (array == NULL)
		return (NULL);

	/* Loop through each element in the array */
	for (i = 0; i < size; i++)
	{
		/* Check for duplicate elements */
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}
		/* If element is unique, insert it into the AVL tree */
		if (j == i)
		{
			if (avl_insert(&tree, array[i]) == NULL)
			{
				/* Deallocate any nodes created before failure */
				free_avl(tree);
				return (NULL);
			}
		}
	}
	return (tree);
}
