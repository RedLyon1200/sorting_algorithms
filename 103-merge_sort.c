#include "sort.h"

/**
 * merge_recursion - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @arr: unsorted list
 * @size: size of array
 * @tmp: hosted memory to sort the list
 *
 * Return: None
 */
void merge_recursion(int *arr, int *tmp, size_t size)
{
	unsigned int middle, i, j = 0, k = 0;

	if (size <= 1)
		return;

	middle = size / 2;

	merge_recursion(arr, tmp, middle);
	merge_recursion(middle + arr, middle + tmp, size - middle);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(arr, middle);
	printf("[right]: ");
	print_array(arr + middle, size - middle);

	for (i = 0; i < size; i++)
	{
		if (j >= size - middle || (k < middle && arr[k] < (arr + middle)[j]))
		{
			tmp[i] = arr[k];
			k++;
		}
		else
		{
			tmp[i] = (arr + middle)[j];
			j++;
		}
	}

	for (i = 0; i < size; i++)
		arr[i] = tmp[i];

	printf("[Done]: ");
	print_array(arr, size);
}

/**
 * merge_sort - call recursion merge sort func
 * @array: unsorted list
 * @size: size of array
 *
 * Return: None
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (!array || size <= 1)
		return;

	tmp = malloc(size * sizeof(int));
	if (!tmp)
		return;

	merge_recursion(array, tmp, size);
}
