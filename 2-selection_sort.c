#include "sort.h"

/**
 * selection_sort - a function that sorts an array of integers in ascending
 * order using the Selection Sort algorithm.
 * @array: pointer to the array
 * @size: size of the array
 * Return: no return value needed
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int hold, min;
	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		hold = array[i];
		min = i + 1;

		for (j = i + 1; j < size - 1; j++)
		{
			if (array[min] > array[j + 1])
				min = j + 1;
		}

		if (array[min] < hold)
		{
			array[i] = array[min];
			array[min] = hold;
			print_array(array, size);
		}
	}
}
