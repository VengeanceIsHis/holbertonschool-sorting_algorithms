#include "sort.h"
/**
 *
 *
 */
void selection_sore(int *array, size_t size)
{
	int *min;
	size_t i, j;
	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size -1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? array + j : min;
		if ((array + i) != min)
		{
			swap_i(array + i, min);
			print_array(array, size);
		}
	}
}
