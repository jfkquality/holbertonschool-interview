#include "binary_trees.h"

/* /\** */
/*  * swap - swap nodes */
/*  * */
/*  * @node1: first node to swap */
/*  * @node2: second node to swap */
/*  * */
/*  * Return: Nothing */
/*  *\/ */
/* void swap(heap_t *node1, heap_t *node2) */
/* { */
/* node1->n = node1->n ^ node2->n; */
/* node2->n = node1->n ^ node2->n; */
/* node1->n = node1->n ^ node2->n; */
/* } */

/**
 * get_height - Get number of levels of heap
 *
 * @root: root node of heap
 *
 * Return: levels
 */
int get_height(heap_t *root) /* , int h) */
{
	int levels = 1;

	if (root == NULL)
		return (0);

	/* if (root->left) */
	/* { */
	levels += get_height(root->left); /* , h + 1); */
	/* } */
	return (levels);
}

/**
 * get_last_node - Get last node of heap
 *
 * @root: root node of heap
 *
 * Return: last node in heap
 */
heap_t *get_last_node(heap_t *root)
{
	int h = get_height(root);
	/* heap_t *left, *right; */

	/* printf("CURRENT HEIGHT: %d\n", h); */
	/* printf("ROOT VALUE -> N: %d\n", root->n); */

	if (h == 1)
		return (root);
	if (h - 1 == get_height(root->right))
		/* printf("RIGHT\n"); */
		return (get_last_node(root->right));
	return (get_last_node(root->left));
}

/**
 * get_size - Get number of nodes in heap. Just for fun function.
 *
 * @tree: root node of heap
 *
 * Return: Number of nodes.
 */
int get_size(heap_t *tree) /* , int size) */
{
	/* int c=0; */
	int size = 1;

	if (tree == NULL)
		return (0);
	size += get_size(tree->left);
	size += get_size(tree->right);
	return (size);
}

/**
 * sift_down - Get number of levels of heap
 *
 * @node: root node of heap
 *
 * Return: levels
 */
void sift_down(heap_t *node)
{
	heap_t *max = NULL;

	if (node->right)
	{
		if (node->right->n > node->left->n)
			max = node->right;
		else
			max = node->left;
	}
	else if (node->left)
		max = node->left;

	if (max && max->n > node->n)
	{
		/* printf("MAX %d, NODE %d, BEFORE SWAP: \n", max->n, node->n); */
		/* swap(max, node); */
		max->n = max->n ^ node->n;
		node->n = max->n ^ node->n;
		max->n = max->n ^ node->n;
		/* printf("MAX %d, NODE %d, AFTER SWAP: \n", max->n, node->n); */
		sift_down(max);
	}
}
/**
 * heap_extract - extract the root node of a Max Binary Heap
 *
 * @root: double pointer to root node
 *
 * Return: value of root node
 */
int heap_extract(heap_t **root)
{

	/* Get heap height */
	/* Get last node  */
	/* Swap last, root nodes */
	/* Sift down root */

	/* height of max heap (complete binary tree). Start at 1*/
	/* traverse left side until node->left is null */
	/* increase level counter for each zleft child found */
	/* save last parent node (i.e. the penultimate row/leve)? */

	int extracted; /* nodes, levels; */
	heap_t *last;


	if (!*root)
		return (0);

	extracted = (*root)->n;

	last = get_last_node(*root);

	/* levels = get_height(*root); */
	/* nodes = get_size(*root); */
	/* printf("HEIGHT %d. SIZE: %d. LAST VALUE: %d\n", levels, nodes, last->n); */

	if (last == *root) /* if one node tree */
	{
		free(last);
		*root = NULL;
		return (extracted);
	}

	if (last->parent->right)
		last->parent->right = NULL;
	else
		last->parent->left = NULL;

	(*root)->n = last->n;

	sift_down(*root);

	free(last);

	return (extracted);
}
