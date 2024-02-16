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


/**
 * selection_sort - Entry point
 *
 * Description: This function selects the minimum value of an unsorted
 * sub-array and positions it in a sorted sub-array
 *
 * @array: pointer to array
 *
 * @size: size of the array
 *
 * Return: Nothing
 */
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
