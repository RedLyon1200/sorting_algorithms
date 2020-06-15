#include "sort.h"

/**
 * heap_sort - sort array using methods heap
 * @array: pointer to array
 * @size: size of array
 * Return: None
 */

void heap_sort(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		if_heap(array, size, i, size);
	for (i = size - 1; i >= 0; i--)
	{
		swap_heap(&array[0], &array[i]);
		if (i != 0)
			print_array(array, size);
		if_heap(array, i, 0, size);
	}
}

/**
 * if_heap - sort array using methods heap
 * @arr: pointer to array
 * @num: size of heap
 * @i: index
 * @size: size of array
 * Return: None
 */

void if_heap(int *arr, int num, int i, size_t size)
{
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < num && arr[left] > arr[max])
		max = left;

	if (right < num && arr[right] > arr[max])
		max = right;

	if (max != i)
	{
		swap_heap(&arr[i], &arr[max]);
		print_array(arr, size);
		if_heap(arr, num, max, size);
	}
}

/**
 * swap_heap - swap integer
 * @a: first value
 * @b: second value
 * Return: None
 */

void swap_heap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
