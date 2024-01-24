#include "sort.h"
#include <stdlib.h>

/**
 * get_max - Get the maximum value in an array.
 * @array: The array of integers.
 * @size: The size of the array.
 * Return: The maximum value.
 */

int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * count_sort - Sort an array based on a significant place value.
 * @array: The array of integers.
 * @size: The size of the array.
 * @exp: The exponent representing the significant place value.
 */
void count_sort(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size);
	int count[10] = {0};
	size_t i;

	if (output == NULL)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	print_array(array, size);
	free(output);
}

/**
 * radix_sort - Sorts an array of integers using the LSD Radix Sort algorithm.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		count_sort(array, size, exp);
	}
}
