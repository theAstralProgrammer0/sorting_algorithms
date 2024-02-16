#include "sort.h"

void swap(int *a, int *b)
{
        int temp;

        temp = *a;
        *a = *b;
        *b = temp;
}


void quick_sort(int *array, size_t size)
{
        int start = 0;
        int end = size - 1;
        int *loc = NULL;

        if (start < end)
        {
                loc = Partition(array, &start, &end);
                quick_sort(array, loc - array);
		print_array(array, size);
                quick_sort(loc + 1, size - (loc - array) - 1);
		print_array(array, size);
        }
}


int *Partition(int *a, int *start, int *end)
{
        int lb = *start;
        int pivot = a[lb];
        int ub = *end;
        int q = lb;

        while (lb < ub)
        {
                while (a[lb] <= pivot)
                        lb++;
                while (a[ub] > pivot)
                        ub--;
                if (lb < ub)
                        swap(&a[lb], &a[ub]);
        }
        swap(&a[ub], &a[q]);
        *start = lb;
        *end = ub;
        return (&a[ub]);
}
