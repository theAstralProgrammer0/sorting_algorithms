#include "sort.h"

/**
 * swap_with_back - Aux function
 *
 * Description: This is a function that swaps two nodes in a dll. The node
 * passed in is swapped with the one at its back (head direction is forward)
 *
 * @list: pointer to the head pointer of the dll
 *
 * @node: Subject node
 *
 * Return: Nothing
 */
void swap_with_back(listint_t **list, listint_t *node)
{
	listint_t *back = NULL;

	back = node->next;
	back->prev = node->prev;
	node->next = back->next;
	if (back->next)
		back->next->prev = node;
	if (node->prev)
		node->prev->next = back;
	back->next = node;
	node->prev = back;
	if (back->prev == NULL)
		*list = back;
}


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
 * cocktail_sort_list - Entry point
 *
 * Description: This is a function that sorts a dll using the cocktail shaker
 * sort algorithm
 *
 * @list: pointer to the head pointer of the dll
 *
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *temp = NULL;
	int sorted = 1, swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	temp = *list;
	while (1)
	{
		sorted = 1;
		while (temp->next)
		{
			swapped = 0;
			if (temp->n > temp->next->n)
			{
				swap_with_back(list, temp);
				print_list(*list);
				sorted = 0;
				swapped = 1;
			}
			if (!swapped)
				temp = temp->next;
		}
		while (temp->prev)
		{
			swapped = 0;
			if (temp->n < temp->prev->n)
			{
				swap_with_front(temp);
				if (temp->prev == NULL)
					*list = temp;
				print_list(*list);
				sorted = 0;
				swapped = 1;
			}
			if (!swapped)
				temp = temp->prev;
		}
		if (sorted)
			break;
	}
}
