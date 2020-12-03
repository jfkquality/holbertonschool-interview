#include "sort.h"

/**
 * swap - swap array indices
 *
 * @arr: array
 * @a: first index to swap
 * @b: second index to swap
 *
 * Return: Nothing
 */
void swap(int *arr, int a, int b)
{
	int c;
	/* size_t size = sizeof(arr) / sizeof(arr[0]); */

	c = arr[a];
	arr[a] = arr[b];
	arr[b] = c;
	/* print_array(arr, size); */

}


/**
 * siftDown - sift nax values down
 *
 * @a: array
 * @start: starting index of array
 * @end: ending index of array
 *
 * Return: Nothing
 */
void siftDown(int *a, size_t start, size_t end)
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
			swap(a, root, child);
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
	size_t start;

	start = (count - 2) / 2;

	while (start > 0)
	{
		siftDown(a, start, count - 1);
		print_array(a, count);
		start--;
	}
	siftDown(a, start, count - 1);
	print_array(a, count);
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

	heapify(array, size);
	/* print_array(array, size); */
	end = size - 1;

	while (end > 0)
	{
		swap(array, end, 0);
		print_array(array, size);
		end--;
		siftDown(array, 0, end);
		print_array(array, size);
	}
}
