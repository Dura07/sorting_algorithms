#include "sort.h"

/**
 * max_get - Get the highest value in an int array.
 * @array: An int array.
 * @size: The array size.
 *
 * Return: The highest/max int in the array.
 */
int max_get(int *array, int size)
{
	int high, x;

	for (high = array[0], x = 1; x < size; x++)
	{
		if (array[x] > high)
			high = array[x];
	}

	return (high);
}

/**
 * counting_sort - Sort an int array from lowest to highest by
 * the counting sort algorithm.
 * @array: An int array.
 * @size: The array size.
 *
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, high, x;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	high = max_get(array, size);
	count = malloc(sizeof(int) * (high + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (x = 0; x < (high + 1); x++)
		count[x] = 0;
	for (x = 0; x < (int)size; x++)
		count[array[x]] += 1;
	for (x = 0; x < (high + 1); x++)
		count[x] += count[x - 1];
	print_array(count, high + 1);

	for (x = 0; x < (int)size; x++)
	{
		sorted[count[array[x]] - 1] = array[x];
		count[array[x]] -= 1;
	}

	for (x = 0; x < (int)size; x++)
		array[x] = sorted[x];

	free(sorted);
	free(count);
}
