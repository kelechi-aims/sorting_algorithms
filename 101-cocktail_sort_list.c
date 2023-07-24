#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @node1: Pointer to the first node to be swapped
 * @node2: Pointer to the second node to be swapped.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;
	if (node2->next)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in
 * ascending order using the Cocktail shaker sort algorithm
 * @list: Double pointer to the list to be sorted
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *left = NULL, *right = NULL, *current = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	do {
		swapped = 0;
		current = left = (*list);
		while (current->next != right)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				swapped = 1;
			}
			else
			{
				current = current->next;
			}
		}
		if (!swapped)
			break;
		swapped = 0;
		right = current;
		while (current->prev != left)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				print_list(*list);
				swapped = 1;
			}
			else
			{
				current = current->prev;
			}
		}
		left = current;
	} while (swapped);
}
