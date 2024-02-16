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
 * bubble_sort - Entry Point
 *
 * Description: This is a function that sorts an array of integers in ascending
 * order using the bubble sort algorithm
 *
 * @array: pointer to the array to be sorted
 *
 * @size: size of the array
 *
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int flag = 0;

	for (i = 0; i < size - 1; i++)
	{
		j = 0;
		while (j < size - 1)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				flag = 1;
			}
			j++;
		}
		if (flag == 0)
			break;
	}
}

