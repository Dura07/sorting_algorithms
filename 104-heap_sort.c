#include "sort.h"

/**
 * heapify - Builds a heap (max heap) from an array.
 * @array: The array to be transformed into a heap.
 * @size: The size of the array.
 * @index: The index of the current root.
 * @total_size: The total size of the array for printing.
 */
void heapify(int *array, size_t size, size_t index, size_t total_size)
{
	size_t largest = index;
	size_t left_child = 2 * index + 1;
	size_t right_child = 2 * index + 2;

	if (left_child < size && array[left_child] > array[largest])
		largest = left_child;

	if (right_child < size && array[right_child] > array[largest])
		largest = right_child;

	if (largest != index)
	{
		int temp = array[index];


		array[index] = array[largest];
		array[largest] = temp;

		print_array(array, total_size);
		heapify(array, size, largest, total_size);
	}
}

/**
 * heap_sort - Sorts an array of integers using the Heap sort algorithm.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2; i > 0; i--)
		heapify(array, size, i - 1, size);

	for (i = size - 1; i > 0; i--)
	{
		int temp = array[0];


		array[0] = array[i];
		array[i] = temp;

		print_array(array, size);
		heapify(array, i, 0, size);
	}
}
