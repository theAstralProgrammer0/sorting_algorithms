#include "sort.h"

void merge_sort(int *array, size_t size)
{
	int lb, ub, *sorted = NULL;

	lb = 0;
	ub = (int)size - 1;

	sorted = (int *)calloc(size, sizeof(int));
	if (sorted == NULL)
		return;

	msort(array, sorted, lb, ub);
}

void msort(int *array, int *sorted, int lb, int ub)
{
	int mid;

	if (lb >= ub)
		return;

	mid = (lb + ub) / 2;

	msort(array, sorted, lb, mid);
		
	msort(array, sorted, mid + 1, ub);

	merge(array, sorted, lb, mid, ub);	
}

void merge(int *array, int *sorted, int lb, int mid, int ub)
{
	int i, j, k;

	i = lb;
	j = mid + 1;
	k = lb;

	printf("Merging...\n");

	printf("[Left]: ");
	print_array(&array[lb], mid - lb + 1);

	printf("[Right]: ");
	print_array(&array[mid + 1], ub - (mid + 1) + 1);
	
	while (i <= mid && j <= ub)
	{
		if (array[i] <= array[j])
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
	if (i > mid)
	{
		while (j <= ub)
		{
			sorted[k] = array[j];
			j++;
			k++;
		}
	}
	else
	{
		while (i <= mid)
		{
			sorted[k] = array[i];
			i++;
			k++;
		}
	}
	for (k = lb; k <= ub; k++)
		array[k] = sorted[k];
	printf("[Done]: ");
	print_array(&array[lb], ub - lb + 1);
	/*print_array(&sorted[lb], ub - lb + 1);*/
}
