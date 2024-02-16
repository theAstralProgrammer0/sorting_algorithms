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

	if (lb < ub)
	{
		loc = Partition(array, lb, ub, size);
		sort(array, lb, loc - 1, size);
		print_array(array, size);
		sort(array, loc + 1, ub, size);
	}
}

void quick_sort(int *array, size_t size)
{
	int lb, ub;

	lb = 0;
	ub = size - 1;
	sort(array, lb, ub, size);
}

int Partition(int *array, int start, int end, __attribute((unused))size_t size)
{
        int pivot = end;

        while (start < end)
        {
                while (array[start] <= array[pivot])
                        start++;
                while (array[end] > array[pivot])
                        end--;
                if (start < end)
		{
                        swap(&array[start], &array[end]);
		}
        }
        swap(&array[end], &array[pivot]);
        return (end);
}
