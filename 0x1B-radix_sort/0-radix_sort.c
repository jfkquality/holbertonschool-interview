#include "sort.h"
#include <math.h>

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

	/* printf("mv-idx: %d. mv-to: %d\n", mv_idx, mv_to); */
	/* mv_to--; */
	while (mv_idx > mv_to)
	{
		arr[mv_idx] = arr[mv_idx - 1];
		digit[mv_idx] = digit[mv_idx - 1];
		mv_idx--;
	}
	arr[mv_to] = tmp;
	digit[mv_to] = tmp2;
	/* print_array(arr, siz); */
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

	lsd = malloc(size);
	if (!lsd)
		return;

	  /* (int)log10(numb) + 1 = digits in num. */
	  /* get max # of digits in array. */
	  /* digit = num % 10^x / 10^(x-1) */
	  /* sort by moving lesser num in front of greater num. */
	  /* e.g. tmp = arr[6] (< arr[2]). Start with idx = 1. */
	  /*    Push all elements from arr{2-5] down 1. */
	  /*    arr[2] = arr[6]. */
	  /* Create lsd arr by finding current digit of each num in array. */
	  /* Sort lsd arr and array (by lsd idx). */

	size2 = (int)size;

	/* printf("size2 %d\n", size2); */

	/* Get max digits */
	while (i++ < size2 - 1)
	{
		/* printf("%d\n", i); */
		/* digits = (int)log10(array[i]) + 1; */
		digits = 0;
		num = array[i];
		while (num > 0)
		{
			num = num / 10;
			digits++;
		}
		/* printf("digits: %d. i = %d\n", digits, i); */
		if (digits > max_digits)
			max_digits = digits;
		/* i++; */
	}
	/* printf("max digits: %d. i = %d\n\n", max_digits, i); */

	i = 0;
	tens = 1;
	while (i++ < max_digits)
	{
		/* tens /= 10; */
		/* printf("i %d\n", i); */
		/* Get max digits per arr[i]? */
		/* tens = (int)pow(10, i); */

		if (i == 10)
			tens /= 10;
		else
			tens *= 10;
		/* printf("tens: %d. i: %d\n", tens, i); */
		/* } */

		j = -1;
		while (j++ < size2 - 1)
		{
			if (i == 10)
			{
				lsd[j] = array[j] / tens / 10;
			}
			else
				lsd[j] = array[j] % tens / (tens / 10);
			/* printf("digit: %d. j = %d\n", lsd[j], j); */
		}
		/* Sort array by lsd */
		k = 0;
		/* printf("SORTING...\n"); */
		while (k++ < size2 - 1)
		{
			l = -1;
			while (l++ < k)
			{
				if (lsd[k] < lsd[l])
				{
					swap(array, lsd, k, l); /* , size); */
					/* break; */
				}
			}
		}
		print_array(array, size);
	}
	/* free(lsd); */
}
