#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/** Auxilliary Functions **/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap(int *a, int *b);
void swap_with_front(listint_t *node);
void swap_with_back(listint_t **list, listint_t *node);
void sorted_swap(listint_t **list, listint_t *unsorted);
int Partition(int *a, int lb, int ub, size_t size);
void sort(int *array, int lb, int ub, size_t size);
void inc_gap(int *gap_p);
void dec_gap(int *gap_p);
void shell_sort(int *array, size_t size);


/** Sorting Algorithms **/
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);

#endif
