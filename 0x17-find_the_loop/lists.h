#ifndef _LISTS_H
#define _LISTS_H

#include <stdio.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

listint_t *find_listint_loop(listint_t *head);
listint_t *add_nodeint(listint_t**, int);
void  free_listint_safe(listint_t**);
void print_listint_safe(listint_t*);
listint_t *get_loop(listint_t *node, listint_t *list);


#endif /*_LISTS_H*/
