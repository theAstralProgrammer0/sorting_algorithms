#include "sort.h"
#define SIZE (size)

void counting_sort(int *array, size_t size)
{
	int i, k, *count = NULL, *sorted = NULL;

	k = 0;
	if (array == NULL)
		return;

	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}

	count = (int *)calloc((size_t)(k + 1), sizeof(int));
	if (count == NULL)
		return;

	sorted = (int *)calloc(size, sizeof(int));
	if (sorted == NULL)
		return;
	
	for (i = 0; i < (int)size; i++)
		++count[array[i]];
	
	for (i = 1 ; i <= k; i++)
		count[i] += count[i - 1];
	print_array(count, k + 1);
	
	for (i = (int)(size - 1); i >= 0; i--)
		sorted[--count[array[i]]] = array[i];

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];
	free(count);
	free(sorted);
}
