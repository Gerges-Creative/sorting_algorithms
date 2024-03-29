#include "sort.h"

/**
 * bubble_sort - a function that sorts an array of integers in ascending order
 * using the Bubble sort algorithm and prints the array after each swap
 * @array: pointer to an array or integers
 * @size: size of the array
 * Return: no return value needed
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, checker;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		checker = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
				print_array(array, size);
				checker = 1;
			}

		}

		if (checker == 0)
			break;

	}
}
