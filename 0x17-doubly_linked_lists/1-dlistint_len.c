#include "lists.h"

/**
 * dlistint_len - it print doubly linked list
 * @h: the list
 * Return: the number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t nodess = 0;

	for (; h; nodess++)
		h = h->next;

	return (nodess);
}
