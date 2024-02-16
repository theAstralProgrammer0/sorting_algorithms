#include "sort.h"

void swap(int *a, int *b)
{
        int temp;

        temp = *a;
        *a = *b;
        *b = temp;
}

void sort(int *array, int lb, int ub, size_t size)
{
	int loc;

	if (lb >= ub || lb < 0)
		return;

	loc = Partition(array, lb, ub, size);
	sort(array, lb, loc - 1, size);
	sort(array, loc + 1, ub, size);
}

void quick_sort(int *array, size_t size)
{
	int lb, ub;

	lb = 0;
	ub = size - 1;
	sort(array, lb, ub, size);
}


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
