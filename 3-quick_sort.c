#include "sort.h"

void quick_sorter(int *array, size_t size, ssize_t low, ssize_t high);
size_t lomuto_partition(int *array, size_t size, ssize_t low, ssize_t high);
void swap(int *array, size_t size, int *a, int *b);

/**
 * quick_sort - a function that sorts an array of integers in ascending
 * order using the Quick Sort algorithm.
 * @array: pointer to the array
 * @size: size of the array
 * Return: no return value needed
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return;

	quick_sorter(array, size, 0, size - 1);
}

/**
 * quick_sorter - a sorter function uses the Lomuto partition scheme
 * @array: the integer array to sort
 * @size: the size of the array
 * @low: the low index of the sort range
 * @high: the high index of the sort range
 * Return: void
 */
void quick_sorter(int *array, size_t size, ssize_t low, ssize_t high)
{
	size_t pi;

	if (low < high)
	{
		pi = lomuto_partition(array, size, low, high);

		quick_sorter(array, size, low, pi - 1);
		quick_sorter(array, size, pi + 1, high);
	}
}

/**
 * lomuto_partition - split the array to partitions
 * @array: the integer array to sort
 * @size: the size of the array
 * @low: the low index of the sort range
 * @high: the high index of the sort range
 * Return: the index of the pivot
 */
size_t lomuto_partition(int *array, size_t size, ssize_t low, ssize_t high)
{
	int pivot = array[high], i, j;

	for (j = i = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			swap(array, size, &array[j], &array[i]);
			i++;
		}
	}
	swap(array, size, &array[i], &array[high]);
	return (i);
}

/**
 * swap - swap two indexes of the array
 * @array: the integer array to sort
 * @size: the size of the array
 * @a: address of the first value
 * @b: address of the second value
 * Return: void
 */
void swap(int *array, size_t size, int *a, int *b)
{
	int temp;

	if (*a != *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
		print_array(array, size);
	}
}
