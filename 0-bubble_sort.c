#include "sort.h"



void bubble_sort(int *array, size_t size)
{
  int sorted = 1;
  int i, j, tmp = 0;

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
