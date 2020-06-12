#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * bubble_sort - function that sorts an array of integers in ascending
 * @array: array to order
 * @size: size of array
 * Return: None
 */

void bubble_sort(int *array, size_t size)
{
	int sorted = 1;
	unsigned int j;
	int tmp = 0;
	unsigned int i;

	if (!array || size <= 1)
		return;

	i = size - 1;

	while (sorted)
	{
		j = 0;
		sorted = 0;
		while (j < i)
		{
			if (array[j] > array[j + 1])
			{
				sorted = 1;
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
			j++;
		}
		i--;
	}
}
