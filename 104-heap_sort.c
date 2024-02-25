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
 * make_heap - transforms the array into a heap using the
 * siftdown method.
 * @array: the array to be transformed.
 * @size: size of the array.
 * @idx: index of the parent being checked.
 *
 * Return: void.
 */
void make_heap(int *array, int size, int idx)
{
	int i = idx, leftchild, rightchild, maxidx;

	leftchild = (i * 2) + 1;
	rightchild = (i * 2) + 2;

	if (leftchild < (int)size && rightchild < (int)size)
		maxidx = array[rightchild] > array[leftchild]
			? rightchild : leftchild; /*if both children are found*/

	else if (leftchild < (int)size && rightchild >= (int)size)
		maxidx = leftchild; /* if only left child is found */

	else			/* base case */
		return;

	if (array[maxidx] > array[i]) /* swaps parent with biggest child :') */
	{
		swap(maxidx, i, array);
		print_array(array, size);
		make_heap(array, size, maxidx); /* Recursive call */
	}
}

/**
 * sift_down - re-heapifies an array after deleting an
 * element from the heap.
 * @array: the array to be reheapified.
 * @size: the size of the array.
 * @idx: the index where we'll stop the heapifying process.
 *
 * Return: void.
 */
void sift_down(int *array, int size, int idx)
{
	int swapflag = 1, parent = 0, rightchild, leftchild;

	while (swapflag)
	{
		swapflag = 0;
		leftchild = (2 * parent) + 1;
		rightchild = (2 * parent) + 2;
		if (leftchild < idx && rightchild < idx)
		{
			if (array[leftchild] > array[rightchild] &&
			    array[leftchild] > array[parent])
			{
				swap(parent, leftchild, array);
				print_array(array, size);
				parent = leftchild;
				swapflag = 1;
			}
			else if (array[rightchild] > array[leftchild] &&
				 array[rightchild] > array[parent])
			{
				swap(parent, rightchild, array);
				print_array(array, size);
				parent = rightchild;
				swapflag = 1;
			}
		}
		else if (leftchild < idx && rightchild >= idx)
		{
			if (array[leftchild] > array[parent])
			{
				swap(parent, leftchild, array);
				print_array(array, size);
				parent = leftchild;
				swapflag = 1;
			}
		}
	}
}

/**
 * heap_sort - sorts an array by creating a heap out of an array
 * then deleting elements from the heap which leaves a sorted array
 * behind.
 * @array: int pointer to the array being sorted.
 * @size: the size of the array.
 *
 * Return: void.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;
	for (i = (int)size - 1; i >= 0; i--)
		make_heap(array, size, i);
	for (i = (int)size - 1; i > 0; i--)
	{
		swap(i, 0, array);
		print_array(array, size);
		sift_down(array, size, i);
	}
}
