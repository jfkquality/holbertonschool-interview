#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

// Array A[] has the items to sort; array B[] is a work array.
void TopDownMergeSort(int A[], int B[], size_t n)
{
	CopyArray(A, 0, n, B);           // one time copy of A[] to B[]
	TopDownSplitMerge(B, 0, n, A);   // sort data from B[] into A[]
}

// Sort the given run of array A[] using array B[] as a source.
// iBegin is inclusive; iEnd is exclusive (A[iEnd] is not in the set).
void TopDownSplitMerge(int B[], size_t iBegin, size_t iEnd, int A[])
{
	if(iEnd - iBegin <= 1)                       // if run size == 1
		return;                                 //   consider it sorted
	// split the run longer than 1 item into halves
	size_t iMiddle = (iEnd + iBegin) / 2;              // iMiddle = mid point
	// recursively sort both runs from array A[] into B[]
	printf("Merging...\n");
	TopDownSplitMerge(A, iBegin,  iMiddle, B);  // sort the left  run
	printf("%d\n", A[iBegin]);
	TopDownSplitMerge(A, iMiddle,    iEnd, B);  // sort the right run
	// merge the resulting runs from array B[] into A[]
	TopDownMerge(B, iBegin, iMiddle, iEnd, A);
}

//  Left source half is A[ iBegin:iMiddle-1].
// Right source half is A[iMiddle:iEnd-1   ].
// Result is            B[ iBegin:iEnd-1   ].
void TopDownMerge(int A[], size_t iBegin, size_t iMiddle, size_t iEnd, int B[])
{
	size_t i = iBegin, j = iMiddle;

	// While there are elements in the left or right runs...
	for (size_t k = iBegin; k < iEnd; k++) {
		// If left run head exists and is <= existing right run head.
		if (i < iMiddle && (j >= iEnd || A[i] <= A[j])) {
			B[k] = A[i];
			i = i + 1;
		} else {
			B[k] = A[j];
			j = j + 1;
		}
	}
}

void CopyArray(int A[], size_t iBegin, size_t iEnd, int B[])
{
	for(size_t k = iBegin; k < iEnd; k++)
		B[k] = A[k];
}
void merge_sort(int *array, size_t size)
{
	int array2[size];

	TopDownMergeSort(array, array2, size);
}
