#include "sort.h"

/**
 * 
 */
void _swap(int *x, int *y)
{
    int tmp;

    tmp = *x;
    *x = *y;
    *y = tmp;
}

int split(int *array, int first, int last, size_t size)
{
    int pivot = array[last], j = first, i;

    for (i = first; i < last; i++)
    {
        if (array[i] <= pivot)
        {
            _swap(&array[j], &array[i]);
            if (j != i)
                print_array(array, size);
            j++;
        }
    }
    _swap(&array[j], &array[last]);
    if (j != i)
        print_array(array, size);

    return (j);
}

void sort_recursion(int *array, int first, int last, size_t size)
{
    int pivot;

    if (first < last)
    {
        pivot = split(array, first, last, size);
        sort_recursion(array, first, pivot - 1, size);
        sort_recursion(array, pivot + 1, last, size);
    }
}

void quick_sort(int *array, size_t size)
{
    if (!array || size <= 1)
        return;

    sort_recursion(array, 0, size - 1, size);
}
