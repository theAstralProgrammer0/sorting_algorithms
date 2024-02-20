#include "sort.h"

/**
 * counting_sort - Entry point
 *
 * Description: This is a sorting algorithm that performs sorting by counting
 * the frequency of numbers and  arranging them in an array using keys to
 * represent their positions
 *
 * @array: pointer to array
 *
 * @size: size of array
 *
 * Return: Nothing
 */
void counting_sort(int *array, size_t size)
{
	int i, k, *count = NULL, *sorted = NULL;

	k = 0;
	if (array == NULL || size == 1)
		return;

	for (i = 0; i < (int)size; i++)
	{
		if (array[i] < 0)
			return;

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
