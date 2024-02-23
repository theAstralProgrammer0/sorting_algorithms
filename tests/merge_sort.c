#include "sort.h"

void copy_array(int *array, int *sorted, int lb, int ub);
void split(int *array, int *sorted, int lb, int ub);
void print_sub_array(const int *array, int lb, int ub);

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


void merge( int *array, int *sorted, int lb, int mid, int ub)
{
	int i, j, k;

	i = lb;
	j = mid + 1;
	k = lb;

	printf("Merging...\n");
	
	printf("[Left]: ");
	print_sub_array(&array[lb], lb, mid);

	printf("[Right]: ");
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

void copy_array(int *array, int *sorted, int lb, int ub)
{
	int k;

	for (k = lb; k <= ub; k++)
		array[k] = sorted[k];
}
