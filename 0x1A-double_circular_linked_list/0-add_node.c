#include <stdio.h>
#include <stdlib.h>
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
	List *node;
	List *head = *list;

	node = malloc(sizeof(List));
	if (node == NULL)
		return (NULL);

	if (list == NULL || str == NULL)
		return (NULL);

	node->str = str;

	if (!head) {
		node->prev = node;
		node->next = node;
		*list = node;
		return (node);
	}
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

	/* List *node; */
	/* List *head = *list; */

	/* node = malloc(sizeof(List)); */
	/* if (node == NULL) */
	/* 	return (NULL); */

	/* 	if (list == NULL || str == NULL) */
	/* 	return (NULL); */

	/* node->str = str; */

	/* if (!head) { */
	/* 	node->prev = node; */
	/* 	node->next = node; */
	/* 	*list = node; */
	/* 	return (node); */
	/* } */
	/* node->prev = head->prev; */
	/* node->prev->next = node; */
	/* head->prev = node; */
	/* node->next = head; */
	/* *list = node; */

	/* return (node); */
}
