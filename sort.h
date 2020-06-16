#ifndef SORT_H
#define SORT_H
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include <unistd.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void swap(listint_t *current, listint_t *move);
void _swap(int *x, int *y);
int split(int *array, int first, int last, size_t size);
void sort_recursion(int *array, int first, int last, size_t size);
void swap_cocktail(listint_t *first, listint_t *last, listint_t **list);
listint_t *create_listint(const int *array, size_t size);
int find_max(int *array, size_t size);
void merge_recursion(int *arr, int *tmp, size_t size);
void swap_heap(int *a, int *b);
void if_heap(int *arr, int n, int i, size_t size);
int find_max_rad(int *array, size_t size);
void rad_sort(int *array, size_t size, int num, int *tmp);
void sort_hoare(int *array, size_t size, int left, int right);
int hoare_split(int *array, size_t size, int left, int right);
void swap_hoare(int *a, int *b);

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

#endif
