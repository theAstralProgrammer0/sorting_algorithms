#include "sort.h"

/**
 * swap - swaps 2 location in a list.
 * @array: int pointer to the array.
 * @a: first location of array to be swapped.
 * @b: second location of array to be swapped.
 *
 * Return: void.
 */
void swap(int a, int b, int *array)
{
	int temp;

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

/**
 * bitonic_merge - merges 2 subarrays into their preferred order
 * of their parent calling function.
 * @array: subarray that the smaller subarrays are being merged into.
 * @size: size of the subarray being merged.
 * @begin: the beginning index of the subarray being merged.
 * @ascending_flag: the order preference of the merged array.
 * @full: the full size of the array.
 *
 * Return: void.
 */
void bitonic_merge(int *array, int size, int begin,
		   int ascending_flag, int full)
{
	int half, i;

	if (size > 1)
	{
		half = size / 2;


		for (i = begin; i < begin + half; i++)
		{
			if (ascending_flag == (array[i] > array[i + half]))
			{
				swap(i, i + half, array);
			}
		}
		bitonic_merge(array, half, begin, ascending_flag, full);
		bitonic_merge(array, half, begin + half, ascending_flag, full);
	}
}

/**
 * bitonic_split - splits an array into multiples of 2 recursively.
 * @array: array that's being split.
 * @size: size of the current array.
 * @begin: begining of the current array.
 * @ascending_flag: determines if list is ascending or decending order.
 * @full: the full size of the calling function.
 *
 * Return: void.
 */
void bitonic_split(int *array, int size, int begin,
		   int ascending_flag, int full)
{
	int half;

	if (size > 1)
	{

		half = size / 2;
		printf("Merging [%d/%d] (%s):\n", size, full,
		       ascending_flag ? "UP" : "DOWN");
		print_array(array + begin, size);

		bitonic_split(array, half, begin, 1, full);
		bitonic_split(array, half, begin + half, 0, full);
		bitonic_merge(array, size, begin, ascending_flag, full);

		printf("Result [%d/%d] (%s):\n", size, full,
		       ascending_flag ? "UP" : "DOWN");
		print_array(array + begin, size);
	}
}

/**
 * bitonic_sort - sorts an array with a size of (2^k)
 * using the bitonic sort algorithm.
 * @array: int pointer to the array being sorted.
 * @size: the size of the array being sorted (2^k).
 *
 * Return: void.
 */
void bitonic_sort(int *array, size_t size)
{
	bitonic_split(array, size, 0, 1, size);
}
