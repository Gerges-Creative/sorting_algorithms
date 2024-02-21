#include "sort.h"

/**
 * shell_sort - a function that sorts an array of integers in ascending order
 * using the Shell Sort algorithm and the knuth sequence n + 1 = n * 3 + 1
 * @array: the array
 * @size: size of the array
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap;
	int temp;

	while (gap <= size  / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];

			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}

			array[j] = temp;
		}

		gap = (gap - 1) / 3;

		print_array(array, size);
	}
}
