#include <stdio.h>
#include <stdlib.h>


int *Partition(int *a, size_t size, int *start, int *end);
void swap(int *a, int *b);

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
		loc = Partition(array, size, &start, &end);
		quick_sort(array, (loc - array));
		quick_sort(loc + 1, size - (loc - array) - 1);
	}
}

int *Partition(int *a, size_t size, int *start, int *end)
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

int main(void)
{
	int a[] = {10, 3, 4, 8, 2, 9, 1};
	quick_sort(a, sizeof(a)/sizeof(int));

	printf("Sorted array: ");
	for (int i = 0; i < sizeof(a)/sizeof(int); i++)
		printf("%d ", a[i]);
	printf("\n");

	return (0);
}
