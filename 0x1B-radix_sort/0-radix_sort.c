#include "sort.h"

/**
 * swap - swap greater value for lesser
 * @arr: orignal arry
 * @digit: array of least signifcant digits
 * @mv_idx: array idx to move
 * @mv_to: array idx to move mv_idx to
 *
 * Return: nothing
 **/
void swap(int *arr, int *digit, int mv_idx, int mv_to) /* , size_t siz) */
{
	int tmp = arr[mv_idx];
	int tmp2 = digit[mv_idx];

	while (mv_idx > mv_to)
	{
		arr[mv_idx] = arr[mv_idx - 1];
		digit[mv_idx] = digit[mv_idx - 1];
		mv_idx--;
	}
	arr[mv_to] = tmp;
	digit[mv_to] = tmp2;
}

/**
 * radix_sort - radix sort
 *
 * @array: array of integers t sort
 * @size: number of elements in array
 *
 * Return: nothing
 **/
void radix_sort(int *array, size_t size)
{
	int *lsd, max_digits = 0;
	int i = -1, j = -1, k, l, tens, digits, size2, num;

	if (size < 2)
		return;

	lsd = malloc(sizeof(int) * size);
	if (!lsd)
		return;

	/* (int)log10(numb) + 1 = digits in num. */
	/* get max # of digits in array. */
	/* digit = num % 10^x / 10^(x-1) */
	/* sort by moving lesser num in front of greater num. */
	/* first shift all values btwn greater/lesser one idx right */
	/* e.g. tmp = arr[6] (< arr[2]). (Start with idx = 1.) */
	/*    Push all elements from arr{2-5] down 1. */
	/*    arr[2] = arr[6]. */
	/* Create lsd arr by finding current lsd of each num in array. */
	/* Sort lsd arr and array (by lsd values). */

	size2 = (int)size;

	/* Get max digits */
	while (i++ < size2 - 1)
	{
		/* digits = (int)log10(array[i]) + 1; */
		digits = 0;
		num = array[i];
		while (num > 0)
		{
			num /= 10;
			digits++;
		}
		if (digits > max_digits)
			max_digits = digits;
	}

	i = 0;
	tens = 1;
	while (i++ < max_digits)
	{
		/* tens = (int)pow(10, i); */

		if (i == 10)
			tens /= 10;
		else
			tens *= 10;

		j = -1;
		while (j++ < size2 - 1)
		{
			if (i == 10) /* Max Int length */
			{
				lsd[j] = array[j] / tens / 10;
			}
			else
				lsd[j] = array[j] % tens / (tens / 10);
		}

		/* Sort arrays by lsd. Start with idx=1 */
		k = 0;
		while (k++ < size2 - 1)
		{
			l = -1; /* Start with idx-0 */
			while (l++ < k)
			{
				if (lsd[k] < lsd[l])
				{
					swap(array, lsd, k, l);
				}
			}
		}
		print_array(array, size);
	}
	free(lsd);
}
