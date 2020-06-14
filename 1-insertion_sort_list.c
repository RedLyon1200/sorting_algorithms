#include "sort.h"

/**
 * insertion_sort_list - sorts a list of doubly bound integers
 * in ascending order using the insert sort algorithm
 * @list: pointer to double linked list
 * Return: None
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *aux = NULL, *move = NULL;

	if (!list || *list == NULL || (*list)->next == NULL)
		return;

	aux = *list;
	current = (*list)->next;

	while (current)
	{
		if (current->n >= aux->n)
		{
			aux = current;
			current = aux->next;
		}
		if (current && current->n < aux->n)
		{
			move = current->prev;
			while (move && move->n > current->n)
			{
				swap(current, move);
				move = current->prev;
				if (!move)
					*list = current;
				print_list(*list);
			}
			current = aux->next;
		}
	}
}

/**
 * swap - swap values
 * @current: current values
 * @move: value to move
 * Return: None
 */
void swap(listint_t *current, listint_t *move)
{
	listint_t *ant = NULL;
	listint_t *pos = NULL;

	if (current->next)
		pos = current->next;
	if (move->prev)
		ant = move->prev;

	move->next = current->next;
	current->next = move;
	current->prev = ant;

	if (pos)
		pos->prev = move;
	if (ant)
		ant->next = current;
	move->prev = current;
}
