#include "sort.h"

/*
 * */


void insertion_sort_list(listint_t **list)
{
	listint_t* tmp, *current;

	if (!(*list))
	{
		return;
	}

	for (current = *list; current->next != NULL; current = current->next)
	{
		for (tmp = current->next; tmp != NULL; tmp = tmp->next)
		{
			if (tmp->n < current->n)
			{
				tmp->prev = current->prev;
				current->next = tmp->next;
				tmp->next = current;
				current->prev = tmp;
			}
		}
	}
	
}
