#include <stdio.h>
#include "binary_trees.h"

/**
 * create_avl - append new node into avl array
 * @parent: node parent
 * @num: node n
 *
 * Return: node
 */

/* avl_t *create_avl(avl_t *tree, avl_t *parent, avl_t *left, ) */
avl_t *create_avl(avl_t *parent, int num)
{
	avl_t *node;

	node = malloc(sizeof(avl_t));
	if (node == NULL)
		return (NULL);
	node->n = num;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/**
 * sorted_array_to_avl - Make AVL from sorted array
 * @array: Pointer to sorted array
 * @size: num of elements in sorted array
 *
 * Return: AVL pointer
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *avl = NULL;
	size_t right;

	if (size > 0)
	{
		right = size / 2;
		if (size % 2 == 0)
			size = size / 2 - 1;
		else
			size = size / 2;

		avl = create_avl(avl, array[size]);
		avl->left = sorted_array_to_avl(array, size);
		avl->right = sorted_array_to_avl(&array[size + 1], right);
	}
	return (avl);
}
