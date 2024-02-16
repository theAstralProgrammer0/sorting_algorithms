#include "sort.h"

/**
 * swap - Aux function
 *
 * Description: This is a function that swaps two integer values
 *
 * @a: fisrt integer
 *
 * @b: second integer
 *
 * Return: Nothing
 */
void swap(int *a, int *b)
{
        int temp;

        temp = *a;
        *a = *b;
        *b = temp;
}


/**
 * Partition - Aux function
 *
 * Description: This is a function that partitions into two based on a pivot
 * value
 *
 * @array: array to be sorted
 *
 * @start: lower bound of array (or partition)
 *
 * @end: upper bound of array (or partition)
 *
 * @size: size of array
 *
 * Return: (int) pivot_idx 
 */
int Partition(int *array, int start, int end, size_t size)
{
        int i, pivot_idx, pivot = array[end];

	pivot_idx = start - 1;
	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			pivot_idx++;
			swap(&array[i], &array[pivot_idx]);
			if (array[i] != array[pivot_idx])
				print_array(array, size);
		}
	}
	pivot_idx++;
	swap(&array[pivot_idx], &array[end]);
	if (array[pivot_idx] != array[end])
		print_array(array, size);
        return (pivot_idx);
}


/**
 * sort - Aux function
 *
 * Description: This is a function that sorts the array by partitions
 *
 * @array: array to be sorted
 *
 * @lb: lower bound of array
 *
 * @ub: upper bound of array
 *
 * @size: size of array
 *
 * Return: Nothing
 */
void sort(int *array, int lb, int ub, size_t size)
{
	int loc;

	if (lb >= ub || lb < 0)
		return;

	loc = Partition(array, lb, ub, size);
	sort(array, lb, loc - 1, size);
	sort(array, loc + 1, ub, size);
}


/**
 * quick_sort - Entry point
 *
 * Description: This is a function that sorts the array using the Lomuto quick
 * sort algorithm
 *
 * @array: array to be sorted
 *
 * @size: size of array
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	int lb, ub;

	lb = 0;
	ub = size - 1;
	sort(array, lb, ub, size);
}
