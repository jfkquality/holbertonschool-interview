#include "sort.h"

/**
 * swap - swap array indices
 *
 * @a: first index to swap
 * @b: second index to swap
 *
 * Return: Nothing
 */
void swap(int *a, int *b)  /* , int a, int b) */
{
	int c;
	/* size_t size = sizeof(arr) / sizeof(arr[0]); */

	c = *a;
	*a = *b;
	*b = c;
	/* c = arr[a]; */
	/* arr[a] = arr[b]; */
	/* arr[b] = c; */
	/* print_array(arr, size); */

}


/**
 * siftDown - sift nax values down
 *
 * @a: array
 * @start: starting index of array
 * @end: ending index of array
 * @arr: original array to allow print_array()
 * @size: original size to all print_array()
 *
 * Return: Nothing
 */
void siftDown(int *a, size_t start, size_t end, int *arr, size_t  size)
{
	size_t root = start;
	size_t child;

	while (root * 2 + 1 <= end)
	{
		child = root * 2 + 1;
		if (child + 1 <= end && a[child] < a[child + 1])
			child++;
		if (a[root] < a[child])
		{
			swap(&a[root], &a[child]);   /* a, root, child); */
			print_array(arr, size);
			root = child;
		}
		else
			return;
	}
}


/**
 * heapify - create heap
 *
 * @a: array
 * @count: number of values in array
 *
 * Return: Nothing
 */
void heapify(int *a, size_t count)
{
	int *arr = a;
	size_t size = count;
	size_t start;

	start = (count - 2) / 2;

	while (start > 0)
	{
		siftDown(a, start, count - 1, arr, size);
		/* print_array(arr, size); */
		start--;
	}
	siftDown(a, start, count - 1, arr, size);
	/* print_array(arr, size); */
}


/**
 * heap_sort - sort array using heap sort
 *
 * @array: array
 * @size: number of values in array
 *
 * Return: Nothing
 */
void heap_sort(int *array, size_t size)
{

	size_t end;

	if (!array || !size || size == 1)
		return;

	heapify(array, size);
	/* print_array(array, size); */
	end = size - 1;

	while (end > 0)
	{
		swap(&array[end], &array[0]);  /* array, end, 0); */
		print_array(array, size);
		end--;
		siftDown(array, 0, end, array, size);
	}
}
