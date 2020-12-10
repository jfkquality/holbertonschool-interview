#include <stdio.h>
#include "search_algos.h"

/**
 * advanced_binary - find first occuurence of value w binary search recursion.
 * @array: pointer to the first element array to traverse
 * @size: is the number of elements in array
 * @value: is the value to search for
 * Return: first index where value is located
 */

int advanced_binary(int *array, size_t size, int value)
{
	size_t m, x;
	signed int found, left;

	left = 1;

	if (size == 0)
		return (-1);
	printf("Searching in array: ");
	for (x = 0; x < size - 1; x++)
		printf("%d, ", array[x]);
	printf("%d\n", array[x]);
	if (size % 2 == 0)
		m  = (size - 1) / 2;
	else
		m = size / 2;
	if (array[m] == value)
	{
		if (left && m > 0)

			found = advanced_binary(array, m + 1, value);

		else
			found = m;
	}
	else if (array[m] < value)
	{
		found = advanced_binary(array + m + 1, size - m - 1, value);

		if (found != (-1))
		{
			left = 0;
			found += m + 1;
		}
	}
	else
	{
		left = 1;
		found = advanced_binary(array, m + 1, value);
	}
	return (found);
}
