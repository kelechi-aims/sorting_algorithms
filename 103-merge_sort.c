#include "sort.h"

/**
 * merge - Merge two sorted subarrays into one sorted array
 * @array: The original array containing two subarrays to be merged
 * @left: Pointer to the start of the left subarray
 * @mid: Pointer to the end of the left subarray
 * @right: Pointer to the end of the right subarray
 * @size: The size of the original array
 */
void merge(int *array, int *left, int *mid, int *right, size_t size)
{
	int *temp_array, *left_end, *right_end;
	size_t i;

	left_end = mid;
	right_end = right;
	temp_array = malloc(size * sizeof(int));
	if (temp_array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		if (left == left_end + 1)
			temp_array[i] = *right++;
		else if (right == right_end + 1)
			temp_array[i] = *left++;
		else if (*left <= *right)
			temp_array[i] = *left++;
		else
			temp_array[i] = *left++;
	}
	for (i = 0; i < size; i++)
		array[i] = temp_array[i];
	free(temp_array);
}

/**
 * merge_sort_recursive - Recursive function to sort an array
 * using Merge sort
 * @array: The original array containing two subarrays to be merged
 * @left: Pointer to the start of the left subarray
 * @right: Pointer to the end of the right subarray
 * @size: The size of the original array
 */
void merge_sort_recursive(int *array, int *left, int *right, size_t size)
{
	int *mid;
	if (left < right)
	{
		mid = left + (right - left) / 2;
		merge_sort_recursive(array, left, mid, size);
		merge_sort_recursive(array, mid + 1, right, size);
		printf("Merging...\n[left]:  ");
		print_array(left, mid -left + 1);
		printf("[right]: ");
		print_array(mid + 1, right - mid);
		merge(array, left, mid, right, size);
		printf("[Done]: ");
		print_array(left, right - left + 1);
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
	if (array == NULL || size < 2)
		return;
	merge_sort_recursive(array, array, array + size -1, size);
}
