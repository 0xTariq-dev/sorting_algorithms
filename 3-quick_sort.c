#include "sort.h"

int lumoto_part(int *arr, int lo, int hi, size_t size);
void Qsort(int *arr, int lo, int hi, size_t size);

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
 * lumoto_part - Handles partioning as 'lumoto' scheme.
 * @array: A pointer to the array to sort.
 * @lo: The start position.
 * @hi: The end position.
 * @size: The size of the array.
 *
 * Return: pivot index.
 */
int lumoto_part(int *arr, int left, int right, size_t size)
{
	int pivot = arr[right];
	int i = left, x;

	for (x = left; x < right; x++)
	{
		if(arr[x] < pivot)
		{
			swap(&arr[i], &arr[x]);
			if (i != x)
				print_array(arr, size);
			i++;
		}
	}
	swap(&arr[i], &arr[right]);
	if (i != x)
		print_array(arr, size);

	return (i);
}

/**
 * sort_helper - Manage low and high caluclations and sorting recursion.
 * @array: A pointer to the array to sort.
 * @lo: The start position.
 * @hi: The end position.
 * @size: The size of the array.
 */
void Qsort(int *arr, int lo, int hi, size_t size)
{
	int pi;

	if (lo < hi)
	{
		pi = lumoto_part(arr, lo, hi, size);

		Qsort(arr, lo, pi - 1, size);
		Qsort(arr, pi + 1, hi, size);
	}
}
/**
 * quick_sort - Sorts an array according to the quick sort algorithm
 *		using 'lumoto' partition scheme.
 * @array: A pointer to the array to sort.
 * @size: The size of the array.
 *
 * Return: Nothing.
 */
void quick_sort(int *array, size_t size)
{
	Qsort(array, 0, (int)size - 1, size);
}