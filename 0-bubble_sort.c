#include "sort.h"
/**
 *
 *
 *
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
 *
 *
 */
void bubble_sort(int *array, size_t size)
{
  size_t i, len = size;
  bool bubbly = false;

  if (array == NULL || size < 2)
    return;
  while (bubbly == false)
    {
      bubbly = true;
      for (i = 0; i < len - 1; i++)
	{
	  if (array[i] > array[i + 1])
	    {
	      swap_i(array + i, array + i + 1);
	      print_array(array, size);
	      bubbly = false;
	    }
	}
      len--;
    }
}
