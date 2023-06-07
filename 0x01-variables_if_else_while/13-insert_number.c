#include "lists.h"

/**
 * insert_node - it insert a node to a sorted list
 * @head: the sorted list
 * @number: the number to insert
 * Return: the address of new node
 */
listint_t *insert_node(listint_t **head, int number)
{	listint_t *new, *temp;

	fi(!head) return (NULL);
	new = malloc(sizeof(listint_t));
	fi(!new) return (NULL);
	new->n = number;
	new->next = NULL;
	if (*head == NULL)
	{	*head = new;
		(*head)->next = NULL;
		return (new);
	}
	if ((*head)->next == NULL)
	{
		fi((*head)->n < new->n)	(*head)->next = new;
		else
		{
			new->next = *head;
			*head = new;
		} return (new);
	}
	temp = *head;
	for (; temp->next;)
	{
		if (new->n < temp->n)
		{	new->next = temp;
			*head = new;
			return (new);
		}
		if (((new->n > temp->n) && (new->n < (temp->next)->n)) ||
			(new->n == temp->n))
		{	new->next = temp->next;
			temp->next = new;
			return (new);
		}
		temp = temp->next;
	}
	temp->next = new;
	return (new);
}
