#include "sort.h"

/**
 * merge - Merge left and right sub-arrays
 * @arr: Full array
 * @left: Left sub-array
 * @right: Right sub-array
 * @size: size of full array
 */
void merge(int *arr, int *left, int *right, size_t size)
{
	int i = 0, j = 0, k = 0;
	int mid = size / 2, end = size - mid;

	printf("Merging...\n[left]: ");
	print_array(left, mid);
	printf("[right]: ");
	print_array(right, end);

	while (i < mid && j < end)
	{
		/* printf("L %d, R %d \n", L[i], R[j]); */
		if (left[i] < right[j])
			arr[k++] = left[i++];
		else
			arr[k++] = right[j++];
	}
	while (i < mid)
		arr[k++] = left[i++];
	while (j < end)
		arr[k++] = right[j++];
	printf("[Done]: ");
	print_array(arr, size);
}

/**
 * merge_sort - Sort array using top-down merge sort
 * @array: Input array
 * @size: Size of array
 */
void merge_sort(int *array, size_t size)
{
	int i, mid = size / 2, left[500], right[500];

	if (!array || size < 2)
		return;

	for (i = 0; i < mid; i++)
		left[i] = array[i];
	for (i = mid; i < (int)size; i++)
		right[i - mid] = array[i];

	merge_sort(left, mid);
	merge_sort(right, size - mid);
	merge(array, left, right, size);
}
