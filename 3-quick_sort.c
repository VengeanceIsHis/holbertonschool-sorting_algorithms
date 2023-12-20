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

int median(int arr[], int low, int middle, int high)
{
  if (arr[low] < arr[middle])
    {
      if (arr[middle] < arr[high])
	  return (middle);
	  else if (arr[low] < arr[high])
	    return (high);
	  else
	    return (low);
    }
  else
    {
      if (arr[low] < arr[high]) {
	return (low);
        } else if (arr[middle] < arr[high]) {
	return (high);
        } else {
	return (middle);
        }
    }
}
size_t partition(int arr[], size_t low, size_t high)
{
  int *pivot, above, below;

  pivot = array + right;
  for (above = below = low; below < high; below++)
    {
      if (array[below] < *pivot)
	{
	  if (above < below)
	    {
	      swap_i(array + below, array + above);
	      print_array(array, size);
	    }
	  above++;
	}
    }
  if (array[above] > *pivot)
    {
      swap_i(array + above, pivot);
      print_array(array, size);
    }
  return (above);
}
}
void helper(int arr[], size_t low, size_t high, size_t size)
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
  if (array == NULL || size < 2)
    return;
  helper(array, size, 0, size - 1);
}
