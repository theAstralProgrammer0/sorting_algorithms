#include "sort.h"

/**
 * swap - Aux function
 *
 * Description: This is a function that swaps two integer values
 *
 * @a: fisrt integer
 *
 * @b: second integer
 *
 * Return: Nothing
 */
void swap(int *a, int *b)
{
        int temp;

        temp = *a;
        *a = *b;
        *b = temp;
}


void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			swap(&array[i], &array[min]);
			print_array(array, size);
		}
	}
}
