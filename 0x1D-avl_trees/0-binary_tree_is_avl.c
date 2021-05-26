#include "binary_trees.h"


/* UTILITY FUNCTIONS TO TEST isBalanced() FUNCTION */

/**
 * max -  returns maximum of two integers
 *
 * @a: first int
 * @b: second int
 *
 * Return: max int
 **/
int max(int a, int b)
{
	return ((a >= b) ? a : b);
}

/**
 * height - Compute the "height" of a tree.
 *
 * @node: root node of tree
 *
 * Return: height
 **/
int height(const binary_tree_t *node)
{
	/* base case tree is empty */
	if (node == NULL)
		return (0);

	/*
	 *  If tree is not empty then height = 1 + max of left
	 *  height and right heights
	*/
	return (1 + max(height(node->left), height(node->right)));
}

/**
 * isBST - Check if tree is a Binary Search Tree.
 *
 * @root: binary tree
 * @min: int min
 * @max: int max
 *
 * Return: o or 1
 **/
int isBST(const binary_tree_t *root, int min, int max)
{

	if (root == NULL)
		return (1);

	if (root->n < min)
		return (0);

	if (root->n > max)
		return (0);

	return (isBST(root->right, root->n, max) &&
		isBST(root->left, min, root->n));
}

/**
 * is_avl - Returns true if binary tree is an AVL Tee/
 *
 * @tree: root node of tree
 * @min: int min
 * @max: int max
 *
 * Return: 1/True or 0/False
 */
int is_avl(const binary_tree_t *tree, int min, int max)
{
	int lh; /* for height of left subtree */
	int rh; /* for height of right subtree */
	/* int min = INT_MIN; */
	/* int max = INT_MAX; */

	/* If tree is empty then return true */
	if (tree == NULL)
		return (1);

	/* Get the height of left and right sub trees */
	lh = height(tree->left);
	rh = height(tree->right);

	if ((abs(lh - rh) <= 1 &&
	     (is_avl(tree->left, min, max) &&
	      is_avl(tree->right, min, max))) &&
	    (isBST(tree->left, min, tree->n - 1) &&
	     isBST(tree->right, tree->n + 1, max)))
		return (1);

	/* If we reach here then tree is not height-balanced */
	return (0);
}

/**
 * binary_tree_is_avl - Returns true if binary tree is an AVL Tee/
 *
 * @tree: root node of tree
 *
 * Return: 1/True or 0/False
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int min = INT_MIN;
	int max = INT_MAX;

	if (tree == NULL)
		return (0);

	return (is_avl(tree, min, max));
}
