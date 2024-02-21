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
 * heapify - Aux function
 *
 * Description: This is the function that transforms an array into a max heap
 *
 * @array: pointer to the array
 *
 * @size: size of the arrayy
 *
 * @idx: index of non-leaf node
 *
 * Return: Nothing
 */
void heapify(int *array, size_t size, int idx)
{
	int l, r, largest;

	largest = idx;

	l = 2 * idx + 1;
	r = 2 * idx + 2;

	if (l < (int)size && array[l] > array[largest])
		largest = l;
	if (r < (int)size && array[r] > array[largest])
		largest = r;

	if (largest != idx)
	{
		swap(&array[idx], &array[largest]);
		printf("Heapify:   ");
		print_array(array, size);
		heapify(array, size, largest);
	}
}

/**
 * heap_sort - Entry point
 *
 * Description: This is the function that sorts an array of integers in
 * ascending order using the heap sort (sift-down) algorithm
 *
 * @array: pointer to the array
 *
 * @size: size of the arrayy
 *
 * Return: Nothing
 */
void heap_sort(int *array, size_t size)
{
	int i, nln;

	if (array == NULL || size == 1)
		return;

	nln = (size / 2) - 1;

	for (i = nln; i >= 0; i--)
		heapify(array, size, i);

	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		printf("Heap Sort: ");
		print_array(array, size);
		heapify(array, size, 0);
	}
}
