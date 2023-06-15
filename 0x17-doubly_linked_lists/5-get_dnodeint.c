#include "lists.h"

/**
 * get_dnodeint_at_index - it Locates a node in a dlistint_t list.
 * @head: its The head of the dlistint_t list.
 * @index: its The node to locate.
 *
 * Return: Iff the node does not exist - NULL.
 *         Otherwise - the address of the located node.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	for (; index != 0; index--)
	{
		if (head == NULL)
			return (NULL);
		head = head->next;
	}

	return (head);
}
