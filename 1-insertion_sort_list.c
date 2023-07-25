#include "sort.h"

/**
* swap_nodes - Swap two nodes in a listint_t list.
* @h: A pointer to the head of the list.
* @n1: A pointer to the first node to swap.
* @n2: The second node to swap.
*/
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
(*n1)->next = n2->next;
if (n2->next != NULL)
n2->next->prev = *n1;
n2->prev = (*n1)->prev;
n2->next = *n1;
if ((*n1)->prev != NULL)
(*n1)->prev->next = n2;
else
*h = n2;
(*n1)->prev = n2;
*n1 = n2->prev;
}

/**
* insertion_sort_list - Sorts a list of integers.
* @list: A pointer to the head of the list.
*
* Description: Uses insertion sort algorithm.
*/
void insertion_sort_list(listint_t **list)
{
listint_t *iter, *insert, *tmp;

if (!list || !*list || !(*list)->next)
return;

for (iter = (*list)->next; iter; iter = tmp)
{
tmp = iter->next;
insert = iter->prev;
while (insert && iter->n < insert->n)
{
swap_nodes(list, &insert, iter);
print_list((const listint_t *)*list);
}
}
}
