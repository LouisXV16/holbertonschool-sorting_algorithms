#include "sort.h"

/**
* insertion_sort_list - Sorts a doubly linked list of integers in ascending
* order using the Insertion sort algorithm.
* @list: A double pointer to the head of the doubly linked list.
*
* Description: Iterates through the list from the second node. For each node,
* it is compared with the nodes before it and placed in the correct position
* by swapping nodes without modifying the integer `n` of any node. After each
* swap, the current state of the list is printed.
*/
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL) /* Handle empty list */
		return;

	listint_t *current, *temp, *next;

	current = (*list)->next; /* Start from the second node */

	/* Iterate over the list */
	while (current != NULL)
	{
		next = current->next;
		temp = current->prev;

		/* Find the correct position for the current node */
		while (temp != NULL && current->n < temp->n)
		{
			/* Swap nodes */
			current->prev = temp->prev;
			temp->next = current->next;
			if (current->next != NULL)
				current->next->prev = temp;
			if (temp->prev != NULL)
				temp->prev->next = current;
			else
				*list = current;
			current->next = temp;
			temp->prev = current;

			/* Print list after swap */
			print_list(*list);

			temp = current->prev;
		}
		current = next;
	}
}
