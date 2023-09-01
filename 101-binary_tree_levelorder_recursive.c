#include "binary_trees.h"

/**
 * struct node_s - Defines a node for a singly linked list.
 * @node: A pointer to a constant binary tree node.
 * @next: A pointer to the next element in the linked list.
 *
 * Description: A struct for encapsulating binary tree nodes in a linked list.
 */
typedef struct node_s
{
	const binary_tree_t *node;
	struct node_s *next;
} ll;

/* Forward declarations of functions */
ll *append(ll *head, const binary_tree_t *btnode);
void free_list(ll *head);
ll *get_children(ll *head, const binary_tree_t *parent);
void levels_rec(ll *head, void (*func)(int));

/**
 * binary_tree_levelorder - Traverses a binary tree in level-order.
 * @tree: A pointer to the root node of the tree.
 * @func: A function pointer to apply on each node's value.
 *
 * Return: Void.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	ll *children = NULL;

	if (!tree || !func)
		return;

	func(tree->n);
	children = get_children(children, tree);
	levels_rec(children, func);

	free_list(children);
}

/**
 * levels_rec - Executes func on each node at the current level.
 * @head: A pointer to the first node in the linked list for the current level.
 * @func: A function pointer to apply on each node's value.
 *
 * Return: Void.
 */
void levels_rec(ll *head, void (*func)(int))
{
	ll *children = NULL, *curr = NULL;

	if (!head)
		return;

	for (curr = head; curr; curr = curr->next)
	{
		func(curr->node->n);
		children = get_children(children, curr->node);
	}
	levels_rec(children, func);
	free_list(children);
}

/**
 * get_children - Adds the children of a parent node to a linked list.
 * @head: A pointer to the first node in the linked list.
 * @parent: A pointer to the parent node.
 *
 * Return: A pointer to the first node in the updated linked list.
 */
ll *get_children(ll *head, const binary_tree_t *parent)
{
	if (parent->left)
		head = append(head, parent->left);
	if (parent->right)
		head = append(head, parent->right);
	return (head);
}

/**
 * append - Appends a binary tree node to the end of a linked list.
 * @head: A pointer to the first node in the linked list.
 * @btnode: A pointer to a constant binary tree node to append.
 *
 * Return: A pointer to the first node in the updated linked list, or NULL if failed.
 */
ll *append(ll *head, const binary_tree_t *btnode)
{
	ll *new = NULL, *last = NULL;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);

	new->node = btnode;
	new->next = NULL;
	if (!head)
		head = new;
	else
	{
		last = head;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	return (head);
}

/**
 * free_list - Deallocates memory for each node in a linked list.
 * @head: A pointer to the first node in the linked list.
 *
 * Return: Void.
 */
void free_list(ll *head)
{
	ll *ptr = NULL;

	while (head)
	{
		ptr = head->next;
		free(head);
		head = ptr;
	}
}
