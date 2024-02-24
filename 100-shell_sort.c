#include "sort.h"

/**
 * get_gap - get the gap
 * @size: size of the array
 * Return: gap of shell sort
 */
size_t get_gap(size_t size)
{
	size_t n;

	n = 1;
	while (n < size)
		n = n * 3 + 1;
	return ((n - 1) / 3);
}

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

	for (gap = get_gap(size); gap; gap = (gap - 1) / 3)
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
