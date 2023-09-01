#include "binary_trees.h"

/**
 * create_node - Creates a new levelorder_queue_t node.
 * @node: The binary tree node for the new node to contain.
 * Return: If an error occurs, NULL. Otherwise, a pointer to the new node.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new = malloc(sizeof(levelorder_queue_t));

	if (!new)
		return (NULL);
	new->node = node;
	new->next = NULL;
	return (new);
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 * @head: A pointer to the head of the queue.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * pint_push - Runs a function on a given binary tree node and
 *             pushes its children into a levelorder_queue_t queue.
 * @node: The binary tree node to print and push.
 * @head: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 * @func: A pointer to the function to call on @node.
 */
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
	       levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *new;

	func(node->n);
	if (node->left)
	{
		new = create_node(node->left);
		if (!new)
			exit(1);
		(*tail)->next = new;
		*tail = new;
	}
	if (node->right)
	{
		new = create_node(node->right);
		if (!new)
			exit(1);
		(*tail)->next = new;
		*tail = new;
	}
}

/**
 * pop - Pops the head of a levelorder_queue_t queue.
 * @head: A double pointer to the head of the queue.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *tmp = (*head)->next;

	free(*head);
	*head = tmp;
}

/**
 * binary_tree_levelorder - Traverses a binary tree using
 *                          level-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *head, *tail;

	if (!tree || !func)
		return;
	head = tail = create_node((binary_tree_t *)tree);
	if (!head)
		return;
	while (head)
	{
		pint_push(head->node, head, &tail, func);
		pop(&head);
	}
}
