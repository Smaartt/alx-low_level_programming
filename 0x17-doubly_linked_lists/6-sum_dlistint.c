#include "lists.h"

/**
 * sum_dlistint - it Sums all the data of a dlistint_t list.
 * @head: its The head of the dlistint_t list.
 *
 * Return: its The sum of all the data.
 */
int sum_dlistint(dlistint_t *head)
{
	int summ = 0;

	while (head)
	{
		summ += head->n;
		head = head->next;
	}

	return (summ);
}
