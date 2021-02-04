#include "lists.h"

/**
 * get_loop - Find starting loop node from find_listint_loop
 *
 * @node: node where loop was found
 * @list: the pointer to the head of the list
 *
 * Return: loop node
 */
listint_t *get_loop(listint_t *node, listint_t *list)
{
	while (1)
	{
		while (node->next != node && node->next != list)
			node = node->next;
		if (node->next == list)
			return (node->next);
		list = list->next;
	}
	return (NULL);
}

/**
 * find_listint_loop - Find if there's a loop in linked list
 *
 * @head: the pointer to the head of the list
 *
 * Return: loop node
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head, *fast = head;

	if (head == NULL)
		return (NULL);

	if (head == head->next)
		return (head);

	while (slow->next)
	{
		slow = slow->next;

		if (fast->next != NULL)
			fast = fast->next->next;
		else
			return (NULL);

		if (slow == NULL || fast == NULL)
			return (NULL);
		if (slow == fast)
			return (get_loop(slow, head));
	}
	return (NULL);
}
