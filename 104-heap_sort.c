#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * sift_down - Performs thhe sift-down operation on a max heap
 * @array: The array to be sorted
 * @size: The size of the array
 * @root: The root node of the max heap
 * @start: The index of the base node of the heap
 */
void sift_down(int *array, size_t size, size_t root, size_t start)
{
	size_t largest, left, right;

	largest = root;
	left = 2 * root + 1;
	right = 2 * root + 2;
	if (left < start && array[left] > array[largest])
		largest = left;
	if (right < start && array[right] > array[largest])
		largest = right;
	if (largest != root)
	{
		swap(&array[root], &array[largest]);
		print_array(array, size);
		sift_down(array, size, largest, start);
	}

}
/**
 * heap_sort - Sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;
	for (i = (size / 2) - 1; i >= 0; i--)
		sift_down(array, size, i, size);
	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		sift_down(array, size, 0, i);
	}

}
