#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @node1: Pointer to the first node to be swapped
 * @node2: Pointer to the second node to be swapped.
 */
void swap_nodes(listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	if (node2->next)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * tranverse_tail - tansverses the list from the tail
 * @list: poniter to the original list
 * @head: pointer to the head of the list
 * @tail: pointer to the tail of the list
 * Return: new head of the list
 */
listint_t *tranverse_tail(listint_t *list, listint_t *head, listint_t *tail)
{
	while (tail && tail->prev)
	{
		if (tail->n < tail->prev->n)
		{
			swap_nodes(tail->prev, tail);
			if (tail->prev == NULL)
				list = tail;
			print_list(list);
		}
		else
			tail = tail->prev;
		if (tail->prev == NULL)
			head = tail;
	}
	return (head);
}
/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in
 * ascending order using the Cocktail shaker sort algorithm
 * @list: Double pointer to the list to be sorted
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1, i = 0, j = 0;
	listint_t *left, *right, *current;

	if (list == NULL || *list == NULL)
		return;
	current = *list;
	for (i = 0; current; i++)
	{
		current = current->next;
	}
	if (i < 2)
		return;
	left = *list;
	while (j < i)
	{
		swapped = 0;
		while (left && left->next)
		{
			if (left->n > left->next->n)
			{
				swap_nodes(left, left->next);
				swapped++;
				if (left->prev->prev == NULL)
					*list = left->prev;
				print_list(*list);
			}
			else
			{
				left = left->next;
			}
			if (left->next == NULL)
				right = left;
		}
		left = tranverse_tail(*list, left, right);
		*list = left;
		j++;
	}
}
