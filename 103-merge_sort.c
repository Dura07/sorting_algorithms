#include "sort.h"
#include <stdlib.h>

/**
 * merge - Merges two subarrays of the array.
 * @array: The array containing the subarrays.
 * @buff: Temporary buffer for merging.
 * @left: Index of the start of the left subarray.
 * @mid: Index of the end of the left subarray (exclusive).
 * @right: Index of the end of the right subarray.
 */
void merge(int *array, int *buff, size_t left, size_t mid, size_t right)
{
	size_t i = left, j = mid, k = 0;

	printf("Merging...\n[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	while (i < mid && j < right)
		buff[k++] = (array[i] < array[j]) ? array[i++] : array[j++];

	while (i < mid)
		buff[k++] = array[i++];

	while (j < right)
		buff[k++] = array[j++];

	for (i = left, k = 0; i < right; i++)
		array[i] = buff[k++];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * recursive_merge_sort - Recursively implements the merge sort algorithm.
 * @array: The array to be sorted.
 * @buff: Temporary buffer for merging.
 * @left: Index of the start of the subarray.
 * @right: Index of the end of the subarray (exclusive).
 */
void recursive_merge_sort(int *array, int *buff, size_t left, size_t right)
{
	size_t mid;

	if (right - left > 1)
	{
		mid = left + (right - left) / 2;
		recursive_merge_sort(array, buff, left, mid);
		recursive_merge_sort(array, buff, mid, right);
		merge(array, buff, left, mid, right);
	}
}

/**
 * merge_sort - Sorts an array of integers using the Merge sort algorithm.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	printf("Splitting...\n");
	recursive_merge_sort(array, buff, 0, size);

	free(buff);
}

