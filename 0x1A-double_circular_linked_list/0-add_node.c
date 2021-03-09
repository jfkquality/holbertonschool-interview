#include "list.h"

/**
 * add_node_end - add node to end (same as add node begin; i.e. in between)
 * @list: double pointer to list
 * @str: string
 *
 * Return: address of new node
 */

List *add_node_end(List **list, char *str)
{
	List *node; /* , *tail; */
	List *head = *list;

	node = malloc(sizeof(List));
	if (node == NULL)
		return (NULL);

	node->str = strdup(str);
	if (!node->str)
	{
		free(node);
		return (NULL);
	}

	if (!head)
	{
		node->prev = node;
		node->next = node;
		*list = node;
		return (node);
	}
	/* tail = head->prev; /\* From Danny. *\/ */
	/* node->prev = tail; */
	/* tail->next = node; */
	node->prev = head->prev;
	node->prev->next = node;
	head->prev = node;
	node->next = head;

	return (node);
}

/**
 * add_node_begin - add node to begin (same as add node end; i.e. in between)
 * @list: double pointer to list
 * @str: string
 *
 * Return: address of new node
 */

List *add_node_begin(List **list, char *str)
{
	return (*list = add_node_end(list, str));
}
