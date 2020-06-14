#include "sort.h"

/**
 * find_max - locate maximimun value in array
 * @array: pointer to array
 * @size: size of array
 * Return: maximun value
 */

int find_max(int *array, size_t size)
{
	int max_value = 0;

	while (size--)
		if (array[size] > max_value)
			max_value = array[size];
	return (max_value);
}

/**
 * counting_sort - sorting method counting
 * @array: pointer to list
 * @size: size of array
 * Return: None
 */

void counting_sort(int *array, size_t size)
{
	int *tmp = NULL, *cpy = NULL;
	unsigned int max = 0, i, j;

	if (!array || size <= 1)
		return;
	max = find_max(array, size);
	tmp = malloc((max + 1) * sizeof(int));
	if (tmp == NULL)
		return;
	for (j = 0; j < max + 1; j++)
		tmp[j] = 0;
	cpy = malloc(size * sizeof(int));
	if (cpy == NULL)
	{
		free(tmp);
		return;
	}
	for (i = 0; i < size; i++)
		tmp[array[i]]++;
	for (j = 1; j < max + 1; j++)
		tmp[j] += tmp[j - 1];
	print_array(tmp, max + 1);

	for (i = 0; i < size; i++)
	{
		tmp[array[i]]--;
		cpy[tmp[array[i]]] = array[i];
	}
	/* for (i = 1; i < max + 1; i++)
	{
		if (tmp[i] == 0)
			i++;
		else
		{
			j = tmp[i];
			if (j != count)
			{
				cpy[count] = i;
				count++;
			}
		}
	} */
	for (j = 0; j < size; j++)
		array[j] = cpy[j];
	free(cpy);
	free(tmp);
}
