#include "sort.h"
/**
 * quick_sort_hoare - sort list in ordes ascending with quick_sort_hoare
 * @array: pointer to list
 * @size: size of array
 * Return: None
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	sort_hoare(array, size, 0, size - 1);
}

/**
 * sort_hoare - implementation of sort algorithm using recursion
 * @array: pointer to list
 * @size: size of array
 * @left: initial array index
 * @right: final array index
 * Return: None
 */

void sort_hoare(int *array, size_t size, int left, int right)
{
	int split;

	if (right - left > 0)
	{
		split = hoare_split(array, size, left, right);
		sort_hoare(array, size, left, split - 1);
		sort_hoare(array, size, split, right);
	}
}

/**
 * hoare_split - split of array
 * @array: pointer to list
 * @size: size of array
 * @left: initial array index
 * @right: final array index
 * Return: None
 */

int hoare_split(int *array, size_t size, int left, int right)
{
	int up, down, current;

	current = array[right];
	for (up = left - 1, down = right + 1; up < down;)
	{
		up++;
		while (array[up] < current)
			up++;
		down--;
		while (array[down] > current)
			down--;
		if (up < down)
		{
			swap_hoare(array + up, array + down);
			print_array(array, size);
		}
	}
	return (up);
}

/**
 * swap_hoare - swap of numbers
 * @a: first number
 * @b: second number
 * Return: None
 */

void swap_hoare(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
