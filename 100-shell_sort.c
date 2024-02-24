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

	if (!array || !size)
		return;

	while (gap < size)
		gap = gap * 3 + 1;

	for (gap = (gap - 1) / 3; gap; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];

			for (j = i; j > gap - 1 && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}
