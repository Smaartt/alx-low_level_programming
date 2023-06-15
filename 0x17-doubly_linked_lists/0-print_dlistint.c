#include "lists.h"

/**
 * print_dlistint - it prints doubly linked list
 * @j: the list
 * Return: the number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t nodess = 0;

	for (; h; nodess++, h = h->next)
		printf("%d\n", h->n);

	return (nodess);
}
