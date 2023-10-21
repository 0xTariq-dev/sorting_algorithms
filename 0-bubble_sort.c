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

/**
 * bubble_sort - Sorts an array according to the bubble sort algorithm.
 * @array: A pointer to the array to sort.
 * @size: The size of the array.
 *
 * Return: Nothing.
 */
void bubble_sort(int *array, size_t size)
{
	int i = 1, x;

	for (; i < (int)size; i++)
	{
		for (x = 0; x < (int)size - i; x++)
		{
			if (array[x] > array[x + 1])
			{
				swap(&array[x + 1], &array[x]);
				print_array(array, size);
			}
		}
	}
}
