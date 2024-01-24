#include "sort.h"
#include <stdio.h>


/**
 * bitonic_sort - Sorts an array of integers in ascending
 * order using Bitonic Sort
 * @array: The array to be sorted
 * @size: Number of elements in the array (should be a power of 2)
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2 || (size & (size - 1)) != 0)
		return;

	printf("Merging [%lu/%lu] (UP):\n", size, size);
	bitonic_merge(array, size, ASCENDING);
}

#define ASCENDING 1


/**
 * bitonic_merge - Merges two subarrays in ascending or descending order
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @dir: Sorting direction (ASCENDING or DESCENDING)
 */
void bitonic_merge(int *array, size_t size, int dir)
{
	if (size > 1)
	{
		size_t mid = size / 2;

		bitonic_compare(array, mid, dir);
		bitonic_merge(array, mid, dir);
		bitonic_merge(array + mid, mid, dir);
	}
}


#define ASCENDING 1

/**
 * bitonic_compare - Compares and swaps elements in a bitonic sequence
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @dir: Sorting direction (ASCENDING or DESCENDING)
 */
void bitonic_compare(int *array, size_t size, int dir)
{
	if (size > 1)
	{
		size_t mid = size / 2;
		size_t i;

	for (i = 0; i < mid; i++)
	{
		if ((array[i] > array[i + mid]) == dir)
			bitonic_swap(&array[i], &array[i + mid]);
	}

	printf("Result [%lu/%lu] (%s):\n", size, size,
			(dir == ASCENDING) ? "UP" : "DOWN");
	print_array(array, size);
	}
}

/**
 * bitonic_swap - Swaps two elements in an array
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 */
void bitonic_swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
