#ifndef _SORT_H
#define _SORT_H

#include <stdio.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void swap(int *arr, int *a);
/* void swap(int *arr, int a, int b); */
void siftDown(int *a, size_t start, size_t end, int *arr, size_t size);
/* void siftDown(int *a, size_t start, size_t end); */
/* void heapify(int *a, int count, int i); */
void heapify(int *a, size_t count);

#endif  /* _SORT_H */
