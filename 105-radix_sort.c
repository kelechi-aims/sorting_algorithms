#include "sort.h"

/**
 * get_max_value - Returns the maximum element in an array
 * @array: The input array
 * @size: The size of the array
 * Return: The maximum element in the array
 */
int get_max_value(int *array, size_t size)
{
	size_t i;
	int max_val;

	max_val = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max_val)
			max_val = array[i];
	}
	return (max_val);
}

/**
 * countSort - Sorts an array of integers
 * using the Counting sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 * @exp: The current digit position (1, 10, 100, etc.)
 */
void countSort(int *array, size_t size, int exp)
{
	int counting_array[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int *output_array, i;

	output_array = malloc(size * sizeof(int));
	if (output_array == NULL)
	{
		return;
	}
	for (i = 0; i < (int)size; i++)
		counting_array[(array[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		counting_array[i] += counting_array[i - 1];
	for (i = (int)size - 1; i >= 0; i--)
	{
		output_array[counting_array[(array[i] / exp) % 10] - 1] = array[i];
		counting_array[(array[i] / exp) % 10]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = output_array[i];
	free(output_array);
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 * using the Radix sort algorithm (LSD)
 * @array: The array to be sorted
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max_val, exp;

	max_val = get_max_value(array, size);
	for (exp = 1; max_val / exp > 0; exp *= 10)
	{
		countSort(array, size, exp);
		print_array(array, size);
	}
}
