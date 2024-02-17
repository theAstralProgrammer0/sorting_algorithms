#include "sort.h"


/**
 * swap - Aux function
 *
 * Description: This function swaps two elements in an array
 *
 * @a: pointer to fisrt element
 *
 * @b: pointer to sencond element
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
 * inc_gap - Aux function
 *
 * Description: This function sets gap to the next value in the Knuth Sequence
 *
 * @gap: The current gap value
 *
 * Return: Nothing
 */
void inc_gap(int *gap)
{
	*gap = ((*gap) * 3) + 1;
}


/**
 * dec_gap - Aux function
 *
 * Description: This function sets gap to the previous value in the Knuth
 * Sequence
 *
 * @gap: The current gap value
 *
 * Return: Nothing
 */
void dec_gap(int *gap)
{
	if (((*gap) - 1) / 3 <= 0)
		*gap = 0;
	else
		*gap = ((*gap) - 1) / 3;
}



/**
 * shell_sort - Entry point
 *
 * Description: This function sorts an array using the Knuth sequence for the
 * gap sequence
 *
 * @array: Pointer to the array
 *
 * @size: Size of the array
 *
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	int i, j, *gap_p, gap = 0, flag = 0, off = 1;

	gap_p = &gap;

	do
	{
		if (flag == 0 && (gap <= (int)size - 1))
		{
			inc_gap(gap_p);
			continue;
		}
		flag = 1;
		dec_gap(gap_p);
		if (gap == 0)
			off = 0;
		
		for (j = gap; j < (int)size; j++)
		{
			for (i = j - gap; i >= 0; i -= gap)
			{
				if (array[i + gap] < array[i])
					swap(&array[i], &array[i + gap]);
				else
					break;
			}
		}
		if (off)
			print_array(array, size);
	} while (gap);
}
