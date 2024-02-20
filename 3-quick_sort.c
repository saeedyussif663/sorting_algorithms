#include "sort.h"

/**
 * swap - swap function
 * @a: First arg
 * @b: Second arg
 * Return: void
 */


void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}


/**
 * partition - find pivot point
 * @array: Array
 * @low: Lowest
 * @high: Highest
 * @size: Size
 *
 * Return: Index
 */

int partition(int *array, int low, int high, size_t size)
{
	int i, j, pivot_value;

	pivot_value = array[high];
	i = (low - 1);

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot_value)
		{
			i++;
			if (&array[i] != &array[j])
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (&array[i + 1] != &array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}


/**
 * quick_sort_recursion - recursion algorithm
 * @array: Array
 * @low: lowest value
 * @high: Highest value
 * @size: Size
 * Return: void
 */

void quick_sort_recursion(int *array, int low, int high, size_t size)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = partition(array, low, high, size);

		quick_sort_recursion(array, low, pivot_idx - 1, size);

		quick_sort_recursion(array, pivot_idx + 1, high, size);
	}
}


/**
 * quick_sort - implement quick sort
 * @array: Array
 * @size: Size
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursion(array, 0, size - 1, size);
}