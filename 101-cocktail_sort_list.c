#include "sort.h"

/**
 * swap_cocktail - swap for cocktail algorithm
 * @first: first value
 * @last: last value
 * @list: double pointer to list
 * Return: None
 */

void swap_cocktail(listint_t *first, listint_t *last, listint_t **list)
{
	last->prev = first->prev;
	first->prev = last;
	first->next = last->next;
	last->next = first;
	if (first->next != NULL)
		first->next->prev = first;
	if (last->prev == NULL)
		*list = last;
	else
		last->prev->next = last;
}

/**
 * cocktail_sort_list - sorting method cocktail algorithm
 * @list: double pointer to list
 * Return: None
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *node_tmp;
	int num_changes = 1;

	node_tmp = *list;

	while (num_changes)
	{
		num_changes = 0;
		for (; node_tmp->next != NULL; node_tmp = node_tmp->next)
		{
			if (node_tmp->n > node_tmp->next->n)
			{
				swap_cocktail(node_tmp, node_tmp->next, list);
				node_tmp = node_tmp->prev;
				print_list(*list);
				num_changes++;
			}
		}

		for (; node_tmp->prev != NULL; node_tmp = node_tmp->prev)
		{
			if (node_tmp->n < node_tmp->prev->n)
			{
				swap_cocktail(node_tmp->prev, node_tmp, list);
				node_tmp = node_tmp->next;
				print_list(*list);
				num_changes++;
			}
		}
	}
}
