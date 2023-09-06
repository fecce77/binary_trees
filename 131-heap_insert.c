#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: Double pointer to the root node of the Heap.
 * @value: Value to store in the node to be inserted.
 *
 * Return: Pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new_node, *swap_node;
	int size, leaves, sub, bit, level, temp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	leaves = size;
	for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
		leaves -= sub;

	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leaves & bit ? tree->right : tree->left;

	new_node = binary_tree_node(tree, value);
	leaves & 1 ? (tree->right = new_node) : (tree->left = new_node);

	swap_node = new_node;
	while (swap_node->parent && (swap_node->n > swap_node->parent->n))
	{
		temp = swap_node->n;
		swap_node->n = swap_node->parent->n;
		swap_node->parent->n = temp;
		new_node = new_node->parent;
		swap_node = swap_node->parent;
	}
	return (new_node);
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: Size of the tree, or 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
