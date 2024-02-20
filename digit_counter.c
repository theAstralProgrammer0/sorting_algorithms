#include <stdio.h>


int counter(int count, int temp)
{
	if (temp == 0)
		return (count);

	temp /= 10;
	count++;
	counter(count, temp);
}

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
int digit_counter(int *array, int idx, int counted, int digit_max, size_t size)
{
	if (idx > (int)size)
		return (digit_max);

	if (digit_max < counted)
		digit_max = counted;

	counted = counter(0, array[idx]);
	digit_counter(array, idx + 1, counted, digit_max, size);
}


/**
 * main - Entry point
 *
 * Description: This function tests the digit_counter function
 *
 * Return: 0 Always Success
 */
int main(void)
{
	int digit_max;
	size_t size;
	int array[] = {9, 8, 45, 22, 6754, 325, 6, 3435, 76743, 565, 79937, 98473963, 477546, 43, 35, 342, 23};


	size = sizeof(array) /sizeof(array[0]);

	digit_max = digit_counter(array, 0, 0, 0, size);

	printf("The maximum number of digits is: %d\n", digit_max);
	return (0);
}
