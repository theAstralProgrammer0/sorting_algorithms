#include "sort.h"


void swap_with_front(listint_t *node)
{
	listint_t *front = NULL;

	front = node->prev;
	front->next = node->next;
	node->prev = front->prev;
	if (front->prev)
		front->prev->next = node;
	if (node->next)
		node->next->prev = front;
	front->prev = node;
	node->next = front;
}


void sorted_swap(listint_t **list, listint_t *unsorted)
{
	listint_t *temp = NULL;

	temp = unsorted;

	while (temp->prev && temp->n < temp->prev->n)
	{
		swap_with_front(temp);
		if (temp->prev == NULL)
		{
			*list = temp;
		}
		print_list(*list);
	}
}


void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL;
	listint_t *unsorted = NULL;

	sorted = *list;
	unsorted = (*list)->next;
	while (unsorted)
	{
		if (unsorted->n < sorted->n)
		{
			sorted_swap(list, unsorted);
		}
		else
			sorted = sorted->next;
		unsorted = sorted->next;
	}
}
