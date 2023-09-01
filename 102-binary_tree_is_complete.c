#include "binary_trees.h"

/**
 * create_node - Allocate and initialize a new levelorder_queue_t node.
 * @node: Pointer to the binary tree node to be included in the new node.
 * Return: NULL if allocation fails, otherwise a pointer to the new node.
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
 * free_queue - Deallocate memory used by a levelorder_queue_t queue.
 * @head: Pointer to the first node in the queue.
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
 * push - Add a node to the end of a levelorder_queue_t queue.
 * @node: Pointer to the binary tree node to be added.
 * @head: Double pointer to the first node in the queue.
 * @tail: Double pointer to the last node in the queue.
 */
void push(binary_tree_t *node, levelorder_queue_t *head,
		  levelorder_queue_t **tail)
{
	levelorder_queue_t *new = create_node(node);

	if (!new)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = new;
	*tail = new;
}

/**
 * pop - Remove the first node from a levelorder_queue_t queue.
 * @head: Double pointer to the first node in the queue.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *tmp = (*head)->next;

	free(*head);
	*head = tmp;
}

/**
 * binary_tree_is_complete - Determine if a binary tree is complete.
 * @tree: Pointer to the root node of the tree to examine.
 * Return: 0 if the tree is NULL or incomplete, 1 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *head, *tail;
	unsigned char flag = 0;

	if (!tree)
		return (0);
	head = tail = create_node((binary_tree_t *)tree);
	if (!head)
		exit(1);
	while (head)
	{
		if (head->node->left)
		{
			if (flag)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right)
		{
			if (flag)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->right, head, &tail);
		}
		else
			flag = 1;
		pop(&head);
	}
	return (1);
}
