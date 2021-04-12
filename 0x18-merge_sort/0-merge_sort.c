#include <stdlib.h>
#include <stdio.h>
#include "sort.h"


/**
 * TopDownMergeSort - Top down merge sort
 * @A: int array A
 * @B: int array B
 * @n: size of array
 *
 * Return: nothing
 *
 **/

void TopDownMergeSort(int A[], int B[], size_t n)
{
	/* Array A[] has the items to sort; array B[] is a work array. */
	CopyArray(A, 0, n, B); /* one time copy of A[] to B[] */
	TopDownSplitMerge(B, 0, n, A); /* sort data from B[] into A[] */
}

/**
 * TopDownSplitMerge - Top down split merge
 * @A: int array A
 * @B: int array B
 * @iBegin: Beginning size of array
 * @iEnd: Ending size of array
 *
 * Return: nothing
 **/

void TopDownSplitMerge(int B[], size_t iBegin, size_t iEnd, int A[])
{
	/* Sort the given run of array A[] using array B[] as a source. */
	/* iBegin is inclusive; iEnd is exclusive (A[iEnd] is not in the set). */

	if (iEnd - iBegin <= 1) /* if run size == 1 */
		return; /* consider it sorted */

	/* split the run longer than 1 item into halves */
	size_t iMiddle = (iEnd + iBegin) / 2; /* iMiddle = mid point */

	/* recursively sort both runs from array A[] into B[] */
	printf("Merging...\n");
	TopDownSplitMerge(A, iBegin, iMiddle, B); /* sort the left  run */
	printf("%d\n", A[iBegin]);
	TopDownSplitMerge(A, iMiddle, iEnd, B);  /* sort the right run */

	/* merge the resulting runs from array B[] into A[] */
	TopDownMerge(B, iBegin, iMiddle, iEnd, A);
}

/**
 * TopDownMerge - Top down merge
 * @A: array A
 * @B: array B
 * @iBegin: Beginning size of array
 * @iMiddle: Middle size of array
 * @iEnd: Ending size of array
 *
 * Return: nothing
 **/

/* Left source half is A[ iBegin:iMiddle-1]. */
/* Right source half is A[iMiddle:iEnd-1   ]. */
/* Result is            B[ iBegin:iEnd-1   ]. */
void TopDownMerge(int A[], size_t iBegin, size_t iMiddle, size_t iEnd, int B[])
{
	size_t i = iBegin, j = iMiddle;

	/* While there are elements in the left or right runs... */
	for (size_t k = iBegin; k < iEnd; k++)
	{
		/* If left run head exists and is <= existing right run head. */
		if (i < iMiddle && (j >= iEnd || A[i] <= A[j]))
		{
			B[k] = A[i];
			i = i + 1;
		} else
		{
			B[k] = A[j];
			j = j + 1;
		}
	}
}

/**
 * CopyArray - Copy array
 * @A: int array A
 * @B: int array B
 * @iBegin: Beginning size of array
 * @iEnd: Ending size of array
 *
 * Return: nothing
 **/

void CopyArray(int A[], size_t iBegin, size_t iEnd, int B[])
{
	for (size_t k = iBegin; k < iEnd; k++)
		B[k] = A[k];
}

/**
 * merge_sort - merge sort function
 * @array: int array
 * @size: Size of array
 *
 * Return: nothing
 **/
void merge_sort(int *array, size_t size)
{
	int array2[size];

	TopDownMergeSort(array, array2, size);
}
