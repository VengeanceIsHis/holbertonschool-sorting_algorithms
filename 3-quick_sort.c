#include "sort.h"
/**
 *swap_i - function that swaps integers in an array
 *@a: first integer to swap
 *@b: second integer to swap
 */
void swap_i(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 *partition - function that handles the partition and prints the array
 *@arr: Array to be viewed
 *@size: size of array
 *@low: Beginning of the array
 *@high:Ending of the array
 */
size_t partition(int arr[], size_t size, int low, int high)
{
	int *pivot, above, below;

	pivot = arr + high;
	for (above = below = low; below < high; below++)
	{
		if (arr[below] < *pivot)
		{
			if (above < below)
			{
				swap_i(arr + below, arr + above);
				print_array(arr, size);
			}
			above++;
		}
	}
	if (arr[above] > *pivot)
	{
		swap_i(arr + above, pivot);
		print_array(arr, size);
	}
	return (above);
}
/**
 *helper - function that recursively calls partition
 *@arr: Array to be used
 *@size: size of the array
 *@low: beginning of the array
 *@high: ending of the array
 */
void helper(int arr[], size_t size, int low, int high)
{
	int part;

	if (high - low > 0)
	{
		part = partition(arr, size, low, high);
		helper(arr, size, low, part - 1);
		helper(arr, size, part + 1, high);
	}
}
/**
*quick_sort - function that handles the quick sort algorithm
*@arr: array to be used
*@size: size of the array
*/
void quick_sort(int arr[], size_t size)
{
	if (arr == NULL || size < 2)
	return;
	helper(arr, size, 0, size - 1);
}
