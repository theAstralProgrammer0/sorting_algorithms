#include "sort.h"

/**
 * swap_with_front - Aux function
 *
 * Description: This function is used to swap a node with the node in front of
 * it in a dll (head node is at forefront)
 *
 * @node: node to be swapped with the node in front of it
 *
 * Return: Nothing
 */
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


/**
 * sorted_swap - Aux function
 *
 * Description: This is the function that goes through the unsorted list and
 * swaps the current node with the one in front
 *
 * @list: pointer to the head pointer of the list
 *
 * @unsorted: pointer to the unsorted part of the list
 *
 * Return: Nothing
 */
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


/**
 * insertion_sort_list - Entry point
 *
 * Description: This is the funtion that sorts an unsorted list into a sorted
 * one using the insertion sort algorithm
 *
 * @list: pointer to the head pointer of the list
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL;
	listint_t *unsorted = NULL;

	if (list == NULL || *list == NULL)
		return;

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
