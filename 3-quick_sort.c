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
  size_t middle;
  int pivot;
  size_t index, j;
    middle = (low + high) / 2;
  index = median(arr, low, middle, high);
  swap_i(&arr[index], &arr[high]);
  pivot = arr[high];
  size_t i = low - 1;
  for (j = low; j < high; j++)
    {
       if (arr[j] <= pivot)
	{
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void helper(int arr[], size_t low, size_t high)
{
  if (low < high)
    {
      size_t pi = partition(arr, low, high);
      helper(arr, low, pi);
      helper(arr, pi + 1, high);
    }
}
void quick_sort(int arr[], size_t size)
{
  helper(arr, 0, size - 1);
}
