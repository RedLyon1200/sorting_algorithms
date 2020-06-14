#include "sort.h"

/**
* shell_sort - sorts an array of integers in ascending order
* using the Shell sort algorithm, using the Knuth sequence
* @array: array of unsorted integers
* @size: size of array
*
* Return: None
*/

void shell_sort(int *array, size_t size)
{
	unsigned int intervalo = 1, i = 0, aux = 0;
	int val = 0;

	if (!array || size <= 1)
		return;

	while (intervalo <= size / 3)
		intervalo = intervalo * 3 + 1;

	while (intervalo > 0)
	{
		for (i = intervalo; i < size; i++)
		{
			val = array[i];
			aux = i;

			while (aux > intervalo - 1 && array[aux - intervalo] > val)
			{
				array[aux] = array[aux - intervalo];
				aux -= intervalo;
			}
			array[aux] = val;
		}
		intervalo = (intervalo - 1) / 3;
		print_array(array, size);
	}
}
