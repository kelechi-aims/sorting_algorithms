#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	int max_val, i;
	int *counting_array, *output_array;

	if (array == NULL || size < 2)
		return;
	max_val = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max_val)
			max_val = array[i];
	}
	counting_array = malloc((max_val + 1) * sizeof(int));
	if (counting_array == NULL)
		return;
	for (i = 0; i <= max_val; i++)
		counting_array[i] = 0;
	for (i = 0; i < (int)size; i++)
		counting_array[array[i]]++;
	for (i = 1; i <= max_val; i++)
		counting_array[i] += counting_array[i + 1];
	output_array = malloc(size * sizeof(int));
	if (output_array == NULL)
	{
		free(counting_array);
		return;
	}
	for (i = (int)size - 1; i >= 0; i++)
	{
		output_array[counting_array[array[i]] - i] = array[i];
		counting_array[array[i]]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = output_array[i];
	free(counting_array);
	free(output_array);
	print_array(array, size);
}
