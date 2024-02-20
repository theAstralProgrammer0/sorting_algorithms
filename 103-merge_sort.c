#include "sort.h"

void copy_array(int *array, int lb, int ub, int *sorted)
{
	int k;

	for (k = lb; k < ub; k++)
		sorted[k] = array[k];
}


void msort(int *array, int lb, int ub, int *sorted)
{
	int mid;

	if ((ub - lb) <= 1)
		return;

	mid = (ub + lb) / 2;

	msort(array, lb, mid, sorted);
	msort(array, mid + 1, ub, sorted);
	
	merge(sorted, lb, mid, ub, array);
}

void merge(int *sorted, int lb, int mid, int ub, int *array)
{
	int i, j, k;

	i = lb;
	j = mid + 1;

	printf("Merging...\n");

	printf("[Left]: ");
	print_array(&array[lb], (mid - lb) + 1);

	printf("[Right]: ");
	print_array(&array[mid + 1], ub - (mid + 1) + 1);

	for (k = lb; k < ub; k++)
	{
		if (i < mid && (j >= ub || array[i] <= array[j]))
		{
			sorted[k] = array[i];
			i++;
		}
		else
		{
			sorted[k] = array[j];
			j++;
		}
	}

	printf("[Done]: ");
	print_array(&array[lb], ub - lb + 1);
}

void merge_sort(int *array, size_t size)
{
	int *sorted = NULL;

	sorted = (int *) calloc(size, sizeof(int));
	if (!sorted)
		return;

	copy_array(array, 0, size, sorted);
	msort(array, 0, size - 1, sorted);
}
