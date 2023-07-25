#include "sort.h"

/**
 * merge - Merge two sorted subarrays into one sorted array
 * @temp: The temp array containing two subarrays to be merged
 * @buff: Array for sorted integers
 * @left: the start of the left subarray
 * @mid: the end of the left subarray
 * @right: the end of the right subarray
 */
void merge(int *temp, int *buff, size_t left, size_t mid, size_t right)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]:  ");
	print_array(temp + left, mid - left);
	printf("[right]: ");
	print_array(temp + mid, right - mid);
	for (i = left, j = mid; i < mid && j < right; k++)
		buff[k] = (temp[i] < temp[j]) ? temp[i++] : temp[j++];
	for (; i < mid; i++)
		buff[k++] = temp[i];
	for (; j < right; j++)
		buff[k++] = temp[j];
	for (i = left, k = 0; i < right; i++)
		temp[i] = buff[k++];
	printf("[Done]: ");
	print_array(temp + left, right - left);
}

/**
 * merge_sort_recursive - Recursive function to sort an array
 * using Merge sort
 * @temp: array containing two subarrays to be merged
 * @buff: array for sorted integers
 * @left: the start of the left subarray
 * @right: the end of the right subarray
 */
void merge_sort_recursive(int *temp, int *buff, size_t left, size_t right)
{
	size_t mid;

	if (right - left > 1)
	{
		mid = left + (right - left) / 2;
		merge_sort_recursive(temp, buff, left, mid);
		merge_sort_recursive(temp, buff, mid, right);
		merge(temp, buff, left, mid, right);
	}
}
/**
 * merge_sort - Sorts an array of integers in ascending order
 *  using the Merge sort algorithm
 *  @array: The array to be sorted
 *  @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp_array;

	if (array == NULL || size < 2)
		return;
	temp_array = malloc(size * sizeof(int));
	if (temp_array == NULL)
		return;
	merge_sort_recursive(array, temp_array, 0, size);
	free(temp_array);
}
