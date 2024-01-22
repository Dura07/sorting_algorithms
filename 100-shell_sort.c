#include <stdio.h>
#include "sort.h"

/**
 * shell_sort - a function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @array: an array of integers
 * @size: size of the array
 * Returns: void
 */

void shell_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j, range;

	range = 1;

	if (array == NULL || size < 2)
		return;
	while (range <= size / 3)
	{
		range = range * 3 + 1;
	}
	while (range > 0)
	{
		for (i = range; i < size; ++i)
		{
			tmp = array[i];
			j = i;

			while (j >= range && array[j - range] > tmp)
			{
				array[j] = array[j - range];
				j -= range;
			}
			array[j] = tmp;
		}
		print_array(array, size);

		range = (range - 1) / 3;
	}
}
