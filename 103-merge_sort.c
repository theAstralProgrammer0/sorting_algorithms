#include "sort.h"

void copy_array(int *array, int *sorted, int lb, int ub);
void split(int *array, int *sorted, int lb, int ub);
void print_sub_array(const int *array, int lb, int ub);

/**
 * merge_sort - Entry point
 *
 * Description: This function sorts an array of unsorted integers using the
 * merge sort algorithm
 *
 * @array: pointer to the array
 *
 * @size: size of the array
 *
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	int lb, ub, *sorted = NULL;

	sorted = (int *) calloc(size, sizeof(int));
	if (!sorted)
		return;

	lb = 0;
	ub = size - 1;

	split(array, sorted, lb, ub);
	free(sorted);
}

/**
 * split - Aux function
 *
 * Description: This function splits the root array into individual leaves of a
 * tree data structure
 *
 * @array: pointer to the array
 *
 * @sorted: pointer to the sorted array
 *
 * @lb: lower bound of sub-arrays
 *
 * @ub: upper bound of sub-arrays
 *
 * Return: Nothing
 */
void split(int *array, int *sorted, int lb, int ub)
{
	int mid;

	if ((ub - lb) >= 1)
	{
		if ((ub + lb) % 2 == 0)
			mid = ((ub + lb) / 2) - 1;
		else
			mid = (ub + lb) / 2;

		split(array, sorted, lb, mid);
		split(array, sorted, mid + 1, ub);
		merge(array, sorted, lb, mid, ub);
	}
	else
		return;
}

/**
 * merge - Aux function
 *
 * Description: This function merges the sub-arrays in the binary tree
 * data structure formed by the split funtion and prints each half of
 * the binary tree
 *
 * @array: pointer to the array
 *
 * @sorted: pointer to the sorted array
 *
 * @lb: lower bound of the sub-arrays
 *
 * @mid: mid point of the array
 *
 * @ub: upper bound of the sub-arrays
 *
 * Return: Nothing
 */
void merge(int *array, int *sorted, int lb, int mid, int ub)
{
	int i, j, k;

	i = lb;
	j = mid + 1;
	k = lb;

	printf("Merging...\n");

	printf("[left]: ");
	print_sub_array(&array[lb], lb, mid);

	printf("[right]: ");
	print_sub_array(&array[mid + 1], mid + 1, ub);

	while (i <= mid && j <= ub)
	{
		if (array[i] < array[j])
		{
			sorted[k] = array[i];
			i++;
		}
		else
		{
			sorted[k] = array[j];
			j++;
		}
		k++;
	}
	while (i <= mid && j > ub)
	{
		sorted[k] = array[i];
		i++;
		k++;
	}
	while (j <= ub && i > mid)
	{
		sorted[k] = array[j];
		j++;
		k++;
	}

	printf("[Done]: ");
	print_sub_array(&sorted[lb], lb, ub);

	copy_array(array, sorted, lb, ub);
}

/**
 * copy_array - Aux function
 *
 * Description: This function copies the elements of one array to another
 *
 * @array: pointer to the array
 *
 * @sorted: pointer to the sorted array
 *
 * @lb: lower bound of array
 *
 * @ub: upper bound of array
 *
 * Return: Nothing
 */
void copy_array(int *array, int *sorted, int lb, int ub)
{
	int k;

	for (k = lb; k <= ub; k++)
		array[k] = sorted[k];
}


/**
 * print_sub_array - Prints the elements of a sub-array of integers
 *
 * @array: The array to be printed
 *
 * @lb: lower bound of sub-array
 *
 * @ub: upper bound of sub_array
 *
 * Return: Nothing
 */
void print_sub_array(const int *array, int lb, int ub)
{
	int i, size;

	size = ub - lb + 1;
	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}
