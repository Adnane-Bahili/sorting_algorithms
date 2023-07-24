#include "sort.h"

void node_swp(listint_t **h, listint_t **n_1, listint_t *n_2);

/**
 * insertion_sort_list -	sorts a doubly linked list of integers using
 *				the Insertion sort algorithm and prints it
 * @list: doubly-linked list of integers head pointer
 *
 * Returns: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *itr, *ins, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (itr = (*list)->next; itr != NULL; itr = tmp)
	{
		tmp = itr->next;
		ins = itr->prev;
		while (ins != NULL && itr->n < ins->n)
		{
			node_swp(list, &ins, itr);
			print_list((const listint_t *)*list);
		}
	}
}
/**
 * node_swp - swaps two nodes in a listint_t doubly-linked list
 * @h: head of the doubly-linked list pointer
 * @n_1: 1st node pointer
 * @n_2: 2nd node
 */
void node_swp(listint_t **h, listint_t **n_1, listint_t *n_2)
{
	(*n_1)->next = n_2->next;
	if (n_2->next != NULL)
		n_2->next->prev = *n_1;
	n_2->prev = (*n_1)->prev;
	n_2->next = *n_1;
	if ((*n_1)->prev != NULL)
		(*n_1)->prev->next = n_2;
	else
		*h = n_2;
	(*n_1)->prev = n_2;
	*n_1 = n_2->prev;
}
