#ifndef _BIN_TREES
#define _BIN_TREES

#include <stdlib.h>
#include <stdio.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

int heap_extract(heap_t **root);
void binary_tree_print(const binary_tree_t *);
/* void swap(heap_t *node1, heap_t *node2); */
/* int get_height(heap_t *node); */
/* heap_t *get_last_node(heap_t *node); */
/* int get_size(heap_t *node); */
/* void sift_down(heap_t *node) */

#endif /* _BIN_TREES */
