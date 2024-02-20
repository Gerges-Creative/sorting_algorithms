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
	size_t i, j, min;
	int hold;

	if (size < 2 || array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

		if (min != i)
		{
			hold = array[i];
			array[i] = array[min];
			array[min] = hold;
			print_array(array, size);
		}
	}
}
