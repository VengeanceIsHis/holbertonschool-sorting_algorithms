#include "sort.h"
/**
 */
void swap_i(int *a, int *b)
{
        int tmp;

        tmp = *a;
        *a = *b;
        *b = tmp;
}
/**
 *
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
void quick_sort(int arr[], size_t size)
{
  if (arr == NULL || size < 2)
    return;
  helper(arr, size, 0, size - 1);
}
