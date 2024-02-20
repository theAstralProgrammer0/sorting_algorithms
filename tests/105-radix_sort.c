#include "sort.h"
void counting_sort_pos(int *array, size_t size, int pos);
int counter(int count, int temp);
int digit_counter(int *array, int idx, int counted, int digit_max, size_t size);



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
void radix_sort(int *array, size_t size)
{
	int digit_max, i, pos;

	if (array == NULL || size == 1)
		return;

	digit_max = digit_counter(array, 0, 0, 0, size);

	for (i = 0, pos = 1; i < digit_max; i++,(pos *= 10))
	{
		counting_sort_pos(array, size, pos);
		print_array(array, size);
	}
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"
int counter(int count, int temp)
{
	if (temp == 0)
		return (count);

	temp /= 10;
	count++;
	counter(count, temp);
}
#pragma GCC diagnostic pop

/**
 * digit_counter - Aux function
 *
 * Description: This function finds the number of digits of the largest number
 * in an array
 *
 * @array: pointer to the array
 *
 * @size: size of the array
 *
 * Return: (int) digit_max
 */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"
int digit_counter(int *array, int idx, int counted, int digit_max, size_t size)
{
	if (idx > (int)size)
		return (digit_max);

	if (digit_max < counted)
		digit_max = counted;

	counted = counter(0, array[idx]);
	digit_counter(array, idx + 1, counted, digit_max, size);
}
#pragma GCC diagnostic pop


void counting_sort_pos(int *array, size_t size, int pos)
{
	int i, k = 0, *count = NULL, *sorted = NULL;

	for (i = 0; i < (int)size; i++)
	{
		if (array[i] < 0)
			return;
		if (array[i] > k)
			k = array[i];
	}

	count = (int *)calloc(k + 1, sizeof(int));
	if (!count)
		return;

	sorted = (int *)calloc(size, sizeof(int));
	if (!sorted)
		return;


	for (i = 0; i < (int)size; i++)
		++count[(array[i] / pos) % 10];
	for (i = 1; i <= k; i++)
		count[i] += count[i - 1];
	for (i = (int)(size - 1); i >= 0; i--)
		sorted[--count[(array[i] / pos) % 10]] = array[i];
	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];
}
