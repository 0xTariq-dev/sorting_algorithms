#include "sort.h"

/**
 * node_swap - Swaps two nodes in a doubly linked list.
 * @l: A pointer to list head.
 * @curr: A pointer to first node.
 * @n: The second node.
 */
void node_swap(listint_t **l, listint_t **curr, listint_t *n)
{
	(*curr)->next = n->next;
	if (n->next != NULL)
		n->next->prev = *curr;

	n->prev = (*curr)->prev;
	n->next = *curr;

	if ((*curr)->prev != NULL)
		(*curr)->prev->next = n;
	else
		*l = n;

	(*curr)->prev = n;
	*curr = n->prev;
}

/**
 * insertion_sort_list - Sort a linked list using insertion sort algorithm.
 *
 * @list: A pointer to list head.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *curr, *ins;

	if (!list || !(*list) || !((*list)->next))
		return;

	for (curr = (*list)->next; curr != NULL; curr = tmp)
	{
		tmp = curr->next;
		ins = curr->prev;

		while (ins != NULL && curr->n < ins->n)
		{
			node_swap(list, &ins, curr);
			print_list((const listint_t *)*list);
		}
	}
}
