#include "sort.h"

/**
 * swap - Swaps two elements in an array.
 * @x: The first element's pointer.
 * @y: The second element's pointer.
 *
 * Return: Nothing.
 */
void swap(int *x, int *y)
{
	int temp = *x;

	*x = *y;
	*y = temp;
}

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t min_i;

	for (i = 0; i < size - 1; i++)
	{
		min_i = i;

		for (j = i + 1; j < size; j++)
		{
				
			if (array[j] < array[min_i])
				min_i = j;	
		}

		if (i != min_i)
		{
			swap(&array[i], &array[min_i]);
			print_array((const int*)array, size);
		}
	}
}
