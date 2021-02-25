#ifndef _SORT_H
#define _SORT_H

#include <stdio.h>

void merge_sort(int *array, size_t size);
void print_array(const int *array, size_t size);

void TopDownMergeSort(int A[],int B[], size_t n);
void TopDownSplitMerge(int B[], size_t iBegin, size_t iEnd, int A[]);
void TopDownMerge(int A[], size_t iBegin, size_t iMiddle, size_t iEnd, int B[]);
void CopyArray(int A[], size_t iBegin, size_t iEnd, int B[]);

#endif /* _SORT_H */
