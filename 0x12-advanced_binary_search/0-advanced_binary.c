#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * advanced_binary - return first occurence of value
 * @array: array pointer
 * @size: # of elements in array
 * @value: value to search for
 *
 * Return: first idx where value found
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t mid;
	int i, found = -1;

	printf("Searching in array: ");
	for (i = 0; i < (int)size; i++)
	{
		if (i != 0)
			printf(",");
		printf(" %d", *(array + i));
	}
	printf("\n");

	if (!array || size == 0)
		return (-1);

	mid = size / 2;

	if (value == *(array + mid))
		/* found++; */
		return (*(array + mid));
		/* /\* return (*(array + mid)); *\/ */

	if (mid > 0)
	{
		if (value < *(array + mid))  /* Go left */
		{
			found = advanced_binary(array, mid, value);
		}
		else /* Go right */
		{
			if (size % 2 != 0)
				found = advanced_binary(array + mid + 1, mid, value);
			else
				found = advanced_binary(array + mid, mid, value);
		}
	}
	return (found);
}
