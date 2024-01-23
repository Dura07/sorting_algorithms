#include <stdio.h>
#include "sort.h"

/**
 * cocktail_sort_list -  a function that sorts a doubly linked list of
 * integers in ascending order using the Cocktail shaker sort algorithm
 * @list: doubly linked list
 * Returns: void
 */

void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *tail;
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	do {
		swapped = 0;

		for (current = *list; current->next != NULL; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, &tail, current, current->next);
				print_list(*list);

				swapped = 1;
			}
		}
		if (!swapped)
			break;

		swapped = 0;

		for (; current->prev != NULL; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, &tail, current->prev, current);
				print_list(*list);

				swapped = 1;
			}
		}
	} while (swapped);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the doubly linked list
 * @tail: Pointer to the tail of the doubly linked list
 * @node1: First node to be swapped
 * @node2: Second node to be swapped
 */
void swap_nodes(listint_t **list, listint_t **tail,
		listint_t *node1, listint_t *node2)

{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;
	else
		*tail = node1;

	if (node1->next != node2)
		node1->next = node2->next;
	else
		node1->next = node2;

	if (node2->prev != node1)
		node2->prev = node1->prev;
	else
		node2->prev = node1;

	node1->prev = node2;
	node2->next = node1;
}
