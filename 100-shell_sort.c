#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending ordering
 * using the Shell sort algorithm, using the Knuth sequence.
 * @array: The array to sort
 * @size: The size of the array
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	unsigned int interval = 1, i, j;
	int temp;

	if (size < 2 || array == NULL)
		return;
	while (interval < size / 3)
		interval = interval * 3 + 1;
	while (interval >= 1)
	{
		for (i = interval; i < size; i++)
		{
			temp = array[i];
			j = i;
			while (j >= interval && array[j - interval] > temp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}
			array[j] = temp;
		}
		print_array(array, size);
		interval = (interval - 1) / 3;
	}
}
