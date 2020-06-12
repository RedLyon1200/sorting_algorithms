#include "sort.h"

/**
 * selection_sort - selcción sort algotithms
 * @array: pointer to unsorted list
 * @size: array size
 * Return: None
 */

void selection_sort(int *array, size_t size)
{
	unsigned int i, j, pos_min;
	int tmp = 0, min;

	if (!array || size <= 1)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array[i];
		pos_min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				pos_min = j;
			}
		}
		if (pos_min != i)
		{
			tmp = array[i];
			array[i] = min;
			array[pos_min] = tmp;
			print_array(array, size);
		}
	}
}
